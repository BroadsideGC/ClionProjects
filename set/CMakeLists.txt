cmake_minimum_required(VERSION 3.2)
project(set)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(set ${SOURCE_FILES} set.cpp set.h)