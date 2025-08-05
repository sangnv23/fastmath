cmake_minimum_required (VERSION 3.2)
project (fastexp)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(fastmath main.cc)
