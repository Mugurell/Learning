cmake_minimum_required(VERSION 3.2)
project(7_5_delegating_constructors)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
#set(CMAKE_WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 "
	)

set(SOURCE_FILES
	main.cpp
	Sales.h
	)


add_executable(7_5_delegating_constructors ${SOURCE_FILES})