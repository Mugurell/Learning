cmake_minimum_required(VERSION 3.3)
project(Read_password_from_cin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Read_password_from_cin ${SOURCE_FILES})