cmake_minimum_required(VERSION 3.17)
project(homework)

set(CMAKE_CXX_STANDARD 14)

include_directories(hw1/code)
include_directories(hw1/demo)

add_executable(variant variant.cpp)
