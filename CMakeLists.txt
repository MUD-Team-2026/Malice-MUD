cmake_minimum_required(VERSION 3.10)
project(MaliceMUD)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 收集所有源文件
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(MaliceMUD ${SOURCES})

target_compile_options(MaliceMUD PRIVATE /utf-8)

target_include_directories(MaliceMUD PRIVATE src)