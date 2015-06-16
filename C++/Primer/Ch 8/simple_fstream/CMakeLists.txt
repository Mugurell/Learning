cmake_minimum_required(VERSION 3.2)
project(simple_fstream)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
	-std=c++11 -Wall -Werror -Wextra -pedantic ")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES main.cpp)
add_executable(simple_fstream ${SOURCE_FILES})