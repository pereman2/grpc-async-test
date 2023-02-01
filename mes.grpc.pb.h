// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: mes.proto
#ifndef GRPC_mes_2eproto__INCLUDED
#define GRPC_mes_2eproto__INCLUDED

#include "mes.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpcmgr {

class MgrApi final {
 public:
  static constexpr char const* service_full_name() {
    return "grpcmgr.MgrApi";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status var(::grpc::ClientContext* context, const ::grpcmgr::event& request, ::grpcmgr::event* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpcmgr::event>> Asyncvar(::grpc::ClientContext* context, const ::grpcmgr::event& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpcmgr::event>>(AsyncvarRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpcmgr::event>> PrepareAsyncvar(::grpc::ClientContext* context, const ::grpcmgr::event& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpcmgr::event>>(PrepareAsyncvarRaw(context, request, cq));
    }
    virtual ::grpc::Status foo(::grpc::ClientContext* context, const ::grpcmgr::Empty& request, ::grpcmgr::event* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpcmgr::event>> Asyncfoo(::grpc::ClientContext* context, const ::grpcmgr::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpcmgr::event>>(AsyncfooRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpcmgr::event>> PrepareAsyncfoo(::grpc::ClientContext* context, const ::grpcmgr::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpcmgr::event>>(PrepareAsyncfooRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void var(::grpc::ClientContext* context, const ::grpcmgr::event* request, ::grpcmgr::event* response, std::function<void(::grpc::Status)>) = 0;
      virtual void var(::grpc::ClientContext* context, const ::grpcmgr::event* request, ::grpcmgr::event* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void foo(::grpc::ClientContext* context, const ::grpcmgr::Empty* request, ::grpcmgr::event* response, std::function<void(::grpc::Status)>) = 0;
      virtual void foo(::grpc::ClientContext* context, const ::grpcmgr::Empty* request, ::grpcmgr::event* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::grpcmgr::event>* AsyncvarRaw(::grpc::ClientContext* context, const ::grpcmgr::event& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::grpcmgr::event>* PrepareAsyncvarRaw(::grpc::ClientContext* context, const ::grpcmgr::event& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::grpcmgr::event>* AsyncfooRaw(::grpc::ClientContext* context, const ::grpcmgr::Empty& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::grpcmgr::event>* PrepareAsyncfooRaw(::grpc::ClientContext* context, const ::grpcmgr::Empty& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status var(::grpc::ClientContext* context, const ::grpcmgr::event& request, ::grpcmgr::event* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpcmgr::event>> Asyncvar(::grpc::ClientContext* context, const ::grpcmgr::event& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpcmgr::event>>(AsyncvarRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpcmgr::event>> PrepareAsyncvar(::grpc::ClientContext* context, const ::grpcmgr::event& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpcmgr::event>>(PrepareAsyncvarRaw(context, request, cq));
    }
    ::grpc::Status foo(::grpc::ClientContext* context, const ::grpcmgr::Empty& request, ::grpcmgr::event* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpcmgr::event>> Asyncfoo(::grpc::ClientContext* context, const ::grpcmgr::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpcmgr::event>>(AsyncfooRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpcmgr::event>> PrepareAsyncfoo(::grpc::ClientContext* context, const ::grpcmgr::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpcmgr::event>>(PrepareAsyncfooRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void var(::grpc::ClientContext* context, const ::grpcmgr::event* request, ::grpcmgr::event* response, std::function<void(::grpc::Status)>) override;
      void var(::grpc::ClientContext* context, const ::grpcmgr::event* request, ::grpcmgr::event* response, ::grpc::ClientUnaryReactor* reactor) override;
      void foo(::grpc::ClientContext* context, const ::grpcmgr::Empty* request, ::grpcmgr::event* response, std::function<void(::grpc::Status)>) override;
      void foo(::grpc::ClientContext* context, const ::grpcmgr::Empty* request, ::grpcmgr::event* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::grpcmgr::event>* AsyncvarRaw(::grpc::ClientContext* context, const ::grpcmgr::event& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::grpcmgr::event>* PrepareAsyncvarRaw(::grpc::ClientContext* context, const ::grpcmgr::event& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::grpcmgr::event>* AsyncfooRaw(::grpc::ClientContext* context, const ::grpcmgr::Empty& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::grpcmgr::event>* PrepareAsyncfooRaw(::grpc::ClientContext* context, const ::grpcmgr::Empty& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_var_;
    const ::grpc::internal::RpcMethod rpcmethod_foo_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status var(::grpc::ServerContext* context, const ::grpcmgr::event* request, ::grpcmgr::event* response);
    virtual ::grpc::Status foo(::grpc::ServerContext* context, const ::grpcmgr::Empty* request, ::grpcmgr::event* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_var : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_var() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_var() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status var(::grpc::ServerContext* /*context*/, const ::grpcmgr::event* /*request*/, ::grpcmgr::event* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestvar(::grpc::ServerContext* context, ::grpcmgr::event* request, ::grpc::ServerAsyncResponseWriter< ::grpcmgr::event>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_foo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_foo() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_foo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status foo(::grpc::ServerContext* /*context*/, const ::grpcmgr::Empty* /*request*/, ::grpcmgr::event* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestfoo(::grpc::ServerContext* context, ::grpcmgr::Empty* request, ::grpc::ServerAsyncResponseWriter< ::grpcmgr::event>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_var<WithAsyncMethod_foo<Service > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_var : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_var() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpcmgr::event, ::grpcmgr::event>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpcmgr::event* request, ::grpcmgr::event* response) { return this->var(context, request, response); }));}
    void SetMessageAllocatorFor_var(
        ::grpc::MessageAllocator< ::grpcmgr::event, ::grpcmgr::event>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::grpcmgr::event, ::grpcmgr::event>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_var() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status var(::grpc::ServerContext* /*context*/, const ::grpcmgr::event* /*request*/, ::grpcmgr::event* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* var(
      ::grpc::CallbackServerContext* /*context*/, const ::grpcmgr::event* /*request*/, ::grpcmgr::event* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_foo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_foo() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpcmgr::Empty, ::grpcmgr::event>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpcmgr::Empty* request, ::grpcmgr::event* response) { return this->foo(context, request, response); }));}
    void SetMessageAllocatorFor_foo(
        ::grpc::MessageAllocator< ::grpcmgr::Empty, ::grpcmgr::event>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::grpcmgr::Empty, ::grpcmgr::event>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_foo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status foo(::grpc::ServerContext* /*context*/, const ::grpcmgr::Empty* /*request*/, ::grpcmgr::event* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* foo(
      ::grpc::CallbackServerContext* /*context*/, const ::grpcmgr::Empty* /*request*/, ::grpcmgr::event* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_var<WithCallbackMethod_foo<Service > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_var : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_var() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_var() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status var(::grpc::ServerContext* /*context*/, const ::grpcmgr::event* /*request*/, ::grpcmgr::event* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_foo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_foo() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_foo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status foo(::grpc::ServerContext* /*context*/, const ::grpcmgr::Empty* /*request*/, ::grpcmgr::event* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_var : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_var() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_var() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status var(::grpc::ServerContext* /*context*/, const ::grpcmgr::event* /*request*/, ::grpcmgr::event* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestvar(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_foo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_foo() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_foo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status foo(::grpc::ServerContext* /*context*/, const ::grpcmgr::Empty* /*request*/, ::grpcmgr::event* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestfoo(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_var : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_var() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->var(context, request, response); }));
    }
    ~WithRawCallbackMethod_var() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status var(::grpc::ServerContext* /*context*/, const ::grpcmgr::event* /*request*/, ::grpcmgr::event* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* var(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_foo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_foo() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->foo(context, request, response); }));
    }
    ~WithRawCallbackMethod_foo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status foo(::grpc::ServerContext* /*context*/, const ::grpcmgr::Empty* /*request*/, ::grpcmgr::event* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* foo(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_var : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_var() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::grpcmgr::event, ::grpcmgr::event>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::grpcmgr::event, ::grpcmgr::event>* streamer) {
                       return this->Streamedvar(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_var() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status var(::grpc::ServerContext* /*context*/, const ::grpcmgr::event* /*request*/, ::grpcmgr::event* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status Streamedvar(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::grpcmgr::event,::grpcmgr::event>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_foo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_foo() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::grpcmgr::Empty, ::grpcmgr::event>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::grpcmgr::Empty, ::grpcmgr::event>* streamer) {
                       return this->Streamedfoo(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_foo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status foo(::grpc::ServerContext* /*context*/, const ::grpcmgr::Empty* /*request*/, ::grpcmgr::event* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status Streamedfoo(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::grpcmgr::Empty,::grpcmgr::event>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_var<WithStreamedUnaryMethod_foo<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_var<WithStreamedUnaryMethod_foo<Service > > StreamedService;
};

}  // namespace grpcmgr


#endif  // GRPC_mes_2eproto__INCLUDED
