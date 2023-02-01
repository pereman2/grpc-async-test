
import mes_pb2_grpc
import mes_pb2
import grpc
from threading import Thread


def wrap(func):
    def wr(*args, **kwargs):
        return func(*args, **kwargs, metadata=[('xd', 's')])
    return wr

channel = grpc.insecure_channel('localhost:50051')
stub = mes_pb2_grpc.MgrApiStub(channel)

def foo(stub):
    event = mes_pb2.Empty()
    response = stub.foo(event)

def var(stub):
    event = mes_pb2.event()
    event.id = "xd"
    response = stub.var(event)

def foot(stub, timespt):
    for _ in range(timespt):
        foo(stub)
import time
import threading 
nthreads = 10
times = 100000
timespt = int(times/nthreads)
threads = []
for _ in range(nthreads):
    threads.append(threading.Thread(target=foot, args=(stub,timespt,)))

t1 = time.time()
for t in threads:
    t.start()

for t in threads:
    t.join()

print(f'time is {time.time() - t1} s')
