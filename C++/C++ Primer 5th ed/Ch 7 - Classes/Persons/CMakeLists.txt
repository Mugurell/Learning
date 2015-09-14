cmake_minimum_required(VERSION 3.2)
project(Persons)

message(STATUS "start running cmake..")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -pedantic")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES
    main.cpp
    Person.cc
    )

add_executable(persons ${SOURCE_FILES})