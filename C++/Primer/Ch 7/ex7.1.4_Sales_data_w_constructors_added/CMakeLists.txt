cmake_minimum_required(VERSION 3.2)
project(Sales)

message(STATUS "start running cmake..")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -pedantic")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES
    sales.cc
    Sales_data.hh
    )

add_executable(sales ${SOURCE_FILES})