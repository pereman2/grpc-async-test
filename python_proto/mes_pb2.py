# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: mes.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\tmes.proto\x12\x07grpcmgr\"\x07\n\x05\x45mpty\"\x13\n\x05\x65vent\x12\n\n\x02id\x18\x01 \x01(\t29\n\x06MgrApi\x12/\n\tsubscribe\x12\x0e.grpcmgr.Empty\x1a\x0e.grpcmgr.event\"\x00\x30\x01\x62\x06proto3')



_EMPTY = DESCRIPTOR.message_types_by_name['Empty']
_EVENT = DESCRIPTOR.message_types_by_name['event']
Empty = _reflection.GeneratedProtocolMessageType('Empty', (_message.Message,), {
  'DESCRIPTOR' : _EMPTY,
  '__module__' : 'mes_pb2'
  # @@protoc_insertion_point(class_scope:grpcmgr.Empty)
  })
_sym_db.RegisterMessage(Empty)

event = _reflection.GeneratedProtocolMessageType('event', (_message.Message,), {
  'DESCRIPTOR' : _EVENT,
  '__module__' : 'mes_pb2'
  # @@protoc_insertion_point(class_scope:grpcmgr.event)
  })
_sym_db.RegisterMessage(event)

_MGRAPI = DESCRIPTOR.services_by_name['MgrApi']
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  _EMPTY._serialized_start=22
  _EMPTY._serialized_end=29
  _EVENT._serialized_start=31
  _EVENT._serialized_end=50
  _MGRAPI._serialized_start=52
  _MGRAPI._serialized_end=109
# @@protoc_insertion_point(module_scope)
