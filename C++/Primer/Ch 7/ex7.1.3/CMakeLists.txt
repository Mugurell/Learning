cmake_minimum_required(VERSION 3.2)
project(ex7_1_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    book_sales.txt
    sales.cc
    Sales_data.hh)

add_executable(ex7_1_3 ${SOURCE_FILES})