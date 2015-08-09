cmake_minimum_required(VERSION 3.2)
project(7_5_6_Debug_ex)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
	-std=c++11 -Wall -Wextra -Werror -pedantic")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
#set(CMAKE_WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES
	main.cpp
	Debug.cpp
	)

add_executable(Debug_ex ${SOURCE_FILES})