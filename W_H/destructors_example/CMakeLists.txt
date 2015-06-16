cmake_minimum_required(VERSION 3.2)
project(classes_destructors_w_H)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow -Woverloaded-virtual \
    -Winvalid-pch -Wcast-align -Wformat=2 -Wformat-nonliteral \
    -Wmissing-declarations -Wmissing-format-attribute -Wmissing-include-dirs \
    -Wredundant-decls -Wswitch-default -Wswitch-enum")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES main.cpp Person.cpp)
add_executable(classes_destructors_w_H ${SOURCE_FILES})