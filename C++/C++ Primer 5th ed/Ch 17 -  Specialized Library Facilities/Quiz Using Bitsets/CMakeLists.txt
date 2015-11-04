cmake_minimum_required(VERSION 3.3)
project(Quiz_Using_Bitsets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow -Woverloaded-virtual \
    -Winvalid-pch -Wcast-align -Wformat=2 -Wformat-nonliteral \
    -Wmissing-declarations -Wmissing-format-attribute -Wmissing-include-dirs \
    -Wredundant-decls -Wswitch-default -Wswitch-enum")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES main.cpp Trivia.cpp)
add_executable(Quiz_Using_Bitsets ${SOURCE_FILES})