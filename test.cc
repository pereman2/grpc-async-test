#include "mes.grpc.pb.h"
#include "mes.pb.h"
#include <google/protobuf/any.h>
#include <grpc++/grpc++.h>
#include <grpc/grpc.h>
#include <thread>

using namespace std;

static size_t foocounter = 0;

class MgrApiService {
public:
  ::grpc::Status var(::grpc::ServerContext *context,
                     const ::grpcmgr::event *request,
                     ::grpcmgr::event *response) {
    if (request->id() == "foo") {
      response->set_id("tupu");
    } else {
      response->set_id("cool");
    }
    return grpc::Status::OK;
  }

  ::grpc::Status foo(::grpc::ServerContext *context,
                     const ::grpcmgr::Empty *request,
                     ::grpcmgr::event *response) {
    std::string s = to_string(foocounter++);
    response->set_id(s);
    return grpc::Status::OK;
  }
};

class ServerImpl final {
public:
  ServerImpl() : nworkers(std::thread::hardware_concurrency()) {}
  ~ServerImpl() {
    server_->Shutdown();
    // Always shutdown the completion queue after the server.
    for (int i = 0; i < nworkers; i++) {
      srv_cqs_[i]->Shutdown();
    }
    for (auto &context : contexts) {
      free(context);
    }
    contexts.clear();
    for (int i = 0; i < nworkers; i++) {
      threads[i].join();
    }
  }

  // There is no shutdown handling in this code.
  void Run() {
    std::string server_address("0.0.0.0:50051");

    grpc::ServerBuilder builder;
    service_handler = new MgrApiService();
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service_" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *asynchronous* service.
    builder.RegisterService(&service_);
    // Finally assemble the server.
    std::cout << "Server listening on " << server_address << std::endl;

    // Proceed to the server's main loop.
    nworkers = std::atoi(getenv("TEST_G_THREADS"));
    std::cout << "Running with " << nworkers << " threads" << std::endl;
    auto nqueues = std::atoi(getenv("TEST_G_QUEUE"));
    std::cout << "Running with " << nqueues << " queues" << std::endl;
    for (int i = 0; i < nqueues; i++) {
      srv_cqs_.push_back(builder.AddCompletionQueue((i % 2) == 0));
    }

    for (int i = 0; i < nqueues; i++) {
      srv_cqs_.push_back(builder.AddCompletionQueue((i % 2) == 0));
    }
    server_ = builder.BuildAndStart();
    for (int i = 0; i < nworkers; i++) {
      std::thread t1(&ServerImpl::HandleRpcs, this, i % nqueues);
      threads.push_back(std::move(t1));
    }
  }

private:
  class CallDataInterface {
  public:
    virtual void proceed() = 0;
  };
  // Class encompasing the state and logic needed to serve a request.
  template <class RequestType, class ResponseType>
  class CallData : public CallDataInterface {
  public:
    typedef std::function<void(
        grpc::ServerContext *, RequestType *,
        ::grpc::ServerAsyncResponseWriter<ResponseType> *,
        ::grpc::CompletionQueue *, ::grpc::ServerCompletionQueue *, void *)>
        service_func_t;
    typedef std::function<grpc::Status(grpc::ServerContext *context,
                                       const RequestType *, ResponseType *)>
        callback_func_t;
    // Take in the "service" instance (in this case representing an asynchronous
    // server) and the completion queue "cq" used for asynchronous communication
    // with the gRPC runtime.
    CallData(service_func_t service_func,
             grpcmgr::MgrApi::AsyncService *service,
             grpc::ServerCompletionQueue *cq, MgrApiService *service_handler,
             callback_func_t cf)
        : service_(service), cq_(cq), server_context(new grpc::ServerContext),
          responder_(server_context.get()), status_(CREATE), callback(cf),
          serviceFunc(service_func) {
      // Invoke the serving logic right away.
      proceed();
    }

    void proceed() override {
      if (status_ == CREATE) {
        // Make this instance progress to the PROCESS state.
        status_ = PROCESS;

        // As part of the initial CREATE state, we *request* that the system
        // start processing SayHello requests. In this request, "this" acts are
        // the tag uniquely identifying the request (so that different CallData
        // instances can serve different requests concurrently), in this case
        // the memory address of this CallData instance.
        serviceFunc(server_context.get(), &request_, &responder_, cq_, cq_,
                    this);
      } else if (status_ == PROCESS) {
        // Spawn a new CallData instance to serve new clients while we process
        // the one for this CallData. The instance will deallocate itself as
        // part of its FINISH state.
        callback(server_context.get(), &request_, &reply_);

        // And we are done! Let the gRPC runtime know we've finished, using the
        // memory address of this instance as the uniquely identifying tag for
        // the event.
        status_ = FINISH;
        responder_.Finish(reply_, grpc::Status::OK, this);
      } else {
        GPR_ASSERT(status_ == FINISH);
        // Once in the FINISH state, deallocate ourselves (CallData).
        status_ = CREATE;
        server_context.reset(new grpc::ServerContext);
        request_ = RequestType();
        responder_ =
            grpc::ServerAsyncResponseWriter<ResponseType>(server_context.get());
        proceed();
      }
    }

  private:
    // The means of communication with the gRPC runtime for an asynchronous
    // server.
    grpcmgr::MgrApi::AsyncService *service_;
    MgrApiService *service_handler;
    // The producer-consumer queue where for asynchronous server notifications.
    grpc::ServerCompletionQueue *cq_;
    // Context for the rpc, allowing to tweak aspects of it such as the use
    // of compression, authentication, as well as to send metadata back to the
    // client.
    std::unique_ptr<grpc::ServerContext> server_context;

    // What we get from the client.
    RequestType request_;
    // What we send back to the client.
    ResponseType reply_;
    service_func_t serviceFunc;
    callback_func_t callback;

    // The means to get back to the client.
    grpc::ServerAsyncResponseWriter<ResponseType> responder_;

    // Let's implement a tiny state machine with the following states.
    enum CallStatus { CREATE, PROCESS, FINISH };
    CallStatus status_; // The current serving state.
  };

  // This can be run in multiple threads if needed.
  void HandleRpcs(int rank) {
#define SETUP_CALL_DATA(SERVICE, REQ, RES, CALLBACK_FUNC)                      \
  new CallData<REQ, RES>(                                                      \
      std::bind(&SERVICE, &service_, std::placeholders::_1,                    \
                std::placeholders::_2, std::placeholders::_3,                  \
                std::placeholders::_4, std::placeholders::_5,                  \
                std::placeholders::_6),                                        \
      &service_, srv_cqs_[rank].get(), service_handler,                        \
      std::bind(&CALLBACK_FUNC, service_handler, std::placeholders::_1,        \
                std::placeholders::_2, std::placeholders::_3));

    // Spawn a new CallData instance to serve new clients.
    auto ncalldata = std::atoi(std::getenv("TEST_G_CD"));
    std::cout << "Setting up " << ncalldata << " calldata contexts for queue"
              << std::endl;
    contexts_mu.lock();
    for (int i = 0; i < ncalldata; i++) {
      auto ctx1 =
          SETUP_CALL_DATA(grpcmgr::MgrApi::AsyncService::Requestfoo,
                          grpcmgr::Empty, grpcmgr::event, MgrApiService::foo);
      contexts.push_back((void*) ctx1);
      auto ctx =
          SETUP_CALL_DATA(grpcmgr::MgrApi::AsyncService::Requestvar,
                          grpcmgr::event, grpcmgr::event, MgrApiService::var);
      contexts.push_back((void*) ctx);
    }
    contexts_mu.unlock();
    void *tag; // uniquely identifies a request.
    bool ok;
    while (true) {
      // Block waiting to read the next event from the completion queue. The
      // event is uniquely identified by its tag, which in this case is the
      // memory address of a CallData instance.
      // The return value of Next should always be checked. This return value
      // tells us whether there is any kind of event or queue is shutting down.
      GPR_ASSERT(srv_cqs_[rank]->Next(&tag, &ok));
      GPR_ASSERT(ok);
      static_cast<CallDataInterface *>(tag)->proceed();
    }
  }

  grpcmgr::MgrApi::AsyncService service_;
  std::unique_ptr<grpc::Server> server_;
  std::vector<std::unique_ptr<grpc::ServerCompletionQueue>> srv_cqs_;
  std::mutex contexts_mu;
  std::vector<void*> contexts;
  unsigned int nworkers;
  std::vector<std::thread> threads;
  MgrApiService *service_handler;
};

int main() {
  ServerImpl server;
  server.Run();
}
