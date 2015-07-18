cmake_minimum_required(VERSION 3.2)
project(Sales_data)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    Sales_data.cpp
    Sales_data.h)

add_executable(Sales_data ${SOURCE_FILES})