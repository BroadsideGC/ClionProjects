cmake_minimum_required(VERSION 3.2)
project(lab)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
 input.txt
 output.txt)
add_executable(lab ${SOURCE_FILES})