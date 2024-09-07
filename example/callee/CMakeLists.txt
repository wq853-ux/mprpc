<<<<<<< HEAD
# set(SRC_LIST userservice.cc ../user.pb.cc)
set(SRC_LIST friendservice.cc ../friend.pb.cc)

set(CMAKE_CXX_FLAGS -pthread)
message(STATUS "CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")

add_executable(provider ${SRC_LIST})
target_link_libraries(provider mprpc protobuf)
=======
set(SRC_LIST userservice.cc ../user.pb.cc)
add_executable(provider ${SRC_LIST})
>>>>>>> 2ea601eed4f7530ca0c589c43c27297b0828fefc
