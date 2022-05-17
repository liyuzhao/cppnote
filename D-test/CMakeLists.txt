# cmake最低版本号要求
cmake_minimum_required(VERSION 3.0.0)
# 设置PROJECT_NAME变量
set(PROJECT_NAME test)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_subdirectory("client")
add_subdirectory("server")