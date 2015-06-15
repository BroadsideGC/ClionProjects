cmake_minimum_required(VERSION 3.2)

project(BIGINT)

include_directories(${BIGINT_SOURCE_DIR})

add_executable(
               big_integer.h
               big_integer.cpp
       )

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -pedantic")
endif()

