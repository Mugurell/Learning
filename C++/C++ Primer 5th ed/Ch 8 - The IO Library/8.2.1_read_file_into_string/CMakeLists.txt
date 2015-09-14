cmake_minimum_required(VERSION 3.2)
project(8_2_1_read_file_into_string)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
	-std=c++11 -Wall -Werror -Wextra -pedantic ")

set(SOURCE_FILES main.cpp)

add_executable(8_2_1_read_file_into_string ${SOURCE_FILES})