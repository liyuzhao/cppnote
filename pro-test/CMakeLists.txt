# cmake最低版本号要求
cmake_minimum_required(VERSION 3.5)
# 设置PROJECT_NAME变量
set(PROJECT_NAME protobuf_demo)
project(${PROJECT_NAME} VERSION 0.1.0)

SET(CMAKE_CXX_STANDARD 11)

# find the protobuf compiler and libraries
find_package(Protobuf REQUIRED)

# check if protobuf was found
if(PROTOBUF_FOUND)
    message("protobuf found")
else()
    message(FATAL_ERROR "Cannot find Protobuf")
endif()

# Generate the .h and .cxx files
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS AddressBook.proto)

# Print path to generated files
message("PROTO_SRCS = ${PROTO_SRCS}")
message("PROTO_HDRS = ${PROTO_HDRS}")
 
# set(CMAKE_BUILD_TYPE Debug)

# 查找当前目录下的所有源文件并存入DIR_SRCS变量
aux_source_directory(src DIR_SRCS)
# 添加一个可编译的目标到工程
add_executable(${PROJECT_NAME} ${DIR_SRCS} ${PROTO_SRCS} ${PROTO_HDRS})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROTOBUF_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR} include)

# link the exe against the libraries
target_link_libraries(${PROJECT_NAME} PUBLIC ${PROTOBUF_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
