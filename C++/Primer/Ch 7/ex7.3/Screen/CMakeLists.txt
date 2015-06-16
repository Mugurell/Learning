cmake_minimum_required(VERSION 3.2)
project(Screen)

message(STATUS "start running cmake..")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -pedantic")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES
    test.cpp
    Screen.cc
    Window_mgr.cpp
    )

add_executable(screen ${SOURCE_FILES})