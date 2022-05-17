# 设置PROJECT_NAME变量
set(PROJECT_CLIENT_NAME client)

project(${PROJECT_CLIENT_NAME} VERSION 0.1.0)
# set(CMAKE_BUILD_TYPE Debug)

#添加头文件
include_directories("include")

# 查找当前目录下的所有源文件并存入DIR_SRCS变量
aux_source_directory(src DIR_SRCS)
# 添加一个可编译的目标到工程
add_executable(${PROJECT_CLIENT_NAME} ${DIR_SRCS})
