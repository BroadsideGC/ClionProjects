cmake_minimum_required(VERSION 3.2)
project(cyclebuf)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(cyclebuf ${SOURCE_FILES} cyclebuf.cpp cyclebuf.h iterator.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++11 -pedantic -O3 -march=haswell")