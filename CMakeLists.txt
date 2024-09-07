# 设置cmake的最低版本和项目名称
cmake_minimum_required(VERSION 3.0)
project(mprpc)

<<<<<<< HEAD
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

# 生产debug版本
set(CMAKE_BUILD_TYPE "Debug")
=======
# 生产debug版本
# set(CMAKE_BUILD_TYPE "Debug")
>>>>>>> 2ea601eed4f7530ca0c589c43c27297b0828fefc

# 设置项目可执行文件输出的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 设置项目库文件输出的路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置项目编译头文件搜索路径 -I
<<<<<<< HEAD
include_directories(${PROJECT_SOURCE_DIR}/src/include)
=======
include_directories(${PROJECT_SOURCE_DIR}/src)
>>>>>>> 2ea601eed4f7530ca0c589c43c27297b0828fefc
include_directories(${PROJECT_SOURCE_DIR}/example)
# 设置项目库文件搜索路径 -L
link_directories(${PROJECT_SOURCE_DIR}/lib)

# src包含了mprpc框架所有的相关代码
<<<<<<< HEAD
add_subdirectory(src)
add_subdirectory(example)
=======
# add_subdirectory(src)
add_subdirectory(example)
>>>>>>> 2ea601eed4f7530ca0c589c43c27297b0828fefc
