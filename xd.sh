~/Downloads/bin/protoc --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` --cpp_out=. --grpc_out=. mes.proto
~/Downloads/bin/protoc --plugin=protoc-gen-grpc_python=`which grpc_python_plugin` --python_out=. --grpc_python_out=. mes.proto
