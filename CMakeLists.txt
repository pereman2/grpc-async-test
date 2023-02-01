cmake_minimum_required(VERSION 3.16)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(xd
  VERSION 17.0.0
  LANGUAGES CXX C ASM)


set(srcs
  test.cc
  mes.pb.cc
  mes.grpc.pb.cc
  )

add_executable(test ${srcs})

find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

message(STATUS "Using gRPC ${gRPC_VERSION}")

set(ABSEIL_LIBS absl::inlined_vector absl::flat_hash_set
  absl::flat_hash_map absl::node_hash_set absl::node_hash_map absl::base absl::throw_delegate absl::raw_hash_set
  absl::hash absl::city absl::low_level_hash absl::raw_logging_internal)

set(_GRPC_LIB gRPC::grpc++)

target_link_libraries(test
  ${_GRPC_LIB}
  ${ABSEIL_LIBS}
  )

