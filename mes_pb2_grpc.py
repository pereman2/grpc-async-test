# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
"""Client and server classes corresponding to protobuf-defined services."""
import grpc

import mes_pb2 as mes__pb2


class MgrApiStub(object):
    """Missing associated documentation comment in .proto file."""

    def __init__(self, channel):
        """Constructor.

        Args:
            channel: A grpc.Channel.
        """
        self.var = channel.unary_unary(
                '/grpcmgr.MgrApi/var',
                request_serializer=mes__pb2.event.SerializeToString,
                response_deserializer=mes__pb2.event.FromString,
                )
        self.foo = channel.unary_unary(
                '/grpcmgr.MgrApi/foo',
                request_serializer=mes__pb2.Empty.SerializeToString,
                response_deserializer=mes__pb2.event.FromString,
                )


class MgrApiServicer(object):
    """Missing associated documentation comment in .proto file."""

    def var(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def foo(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_MgrApiServicer_to_server(servicer, server):
    rpc_method_handlers = {
            'var': grpc.unary_unary_rpc_method_handler(
                    servicer.var,
                    request_deserializer=mes__pb2.event.FromString,
                    response_serializer=mes__pb2.event.SerializeToString,
            ),
            'foo': grpc.unary_unary_rpc_method_handler(
                    servicer.foo,
                    request_deserializer=mes__pb2.Empty.FromString,
                    response_serializer=mes__pb2.event.SerializeToString,
            ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
            'grpcmgr.MgrApi', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))


 # This class is part of an EXPERIMENTAL API.
class MgrApi(object):
    """Missing associated documentation comment in .proto file."""

    @staticmethod
    def var(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/grpcmgr.MgrApi/var',
            mes__pb2.event.SerializeToString,
            mes__pb2.event.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def foo(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/grpcmgr.MgrApi/foo',
            mes__pb2.Empty.SerializeToString,
            mes__pb2.event.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)