cmake_minimum_required(VERSION 3.21)
project(fnv1a)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 23)

add_executable(example "${CMAKE_SOURCE_DIR}/examples/example.c")
add_executable(example_compiletime "${CMAKE_SOURCE_DIR}/examples/example_compiletime.cpp")