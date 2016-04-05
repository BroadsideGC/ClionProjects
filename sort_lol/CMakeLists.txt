cmake_minimum_required(VERSION 3.4)
project(sort_lol)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -march=native")

set(SOURCE_FILES main.cpp)
add_executable(sort_lol ${SOURCE_FILES})