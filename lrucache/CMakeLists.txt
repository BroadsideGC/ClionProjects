cmake_minimum_required(VERSION 3.2)
project(lrucache)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(lrucache ${SOURCE_FILES} lru_cache.cpp lru_cache.h)