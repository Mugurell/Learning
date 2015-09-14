cmake_minimum_required(VERSION 3.2)
project(7_6_Bank_static_members_)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
	-std=c++11 -Wall -Werror -Wextra -pedantic ")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES main.cpp )

add_executable(7_6_Bank_static_members_ ${SOURCE_FILES})