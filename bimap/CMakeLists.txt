cmake_minimum_required(VERSION 3.2)
project(bimap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(bimap ${SOURCE_FILES} bimap.cpp bimap.h left_iterator.cpp right_iterator.cpp)