cmake_minimum_required(VERSION 3.2)
project(Cars_test_w_H)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -pedantic")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES
	Car.cc
	main.cc
	)

add_executable(cars ${SOURCE_FILES})