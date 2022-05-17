# cmake最低版本号要求
cmake_minimum_required(VERSION 3.0.0)
# 设置PROJECT_NAME变量
set(PROJECT_NAME test)

project(${PROJECT_NAME} VERSION 0.1.0)
# set(CMAKE_BUILD_TYPE Debug)

# 查找当前目录下的所有源文件并存入DIR_SRCS变量
aux_source_directory(src DIR_SRCS)
# 添加一个可编译的目标到工程
add_executable(${PROJECT_NAME} ${DIR_SRCS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
