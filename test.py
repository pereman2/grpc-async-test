
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


import time
t1 = time.time()
for i in range(10000):
    foo(stub)
    var(stub)

print(f'time is {time.time() - t1} s')
