cmake_minimum_required(VERSION 3.2)
project(Synthesized_Copy_Constructor_vs_Defined)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -std=c++14 -Wall -Wextra -pedantic -Wshadow -Woverloaded-virtual \
    -Winvalid-pch -Wcast-align -Wformat=2 -Wformat-nonliteral \
    -Wmissing-declarations -Wmissing-format-attribute -Wmissing-include-dirs \
    -Wredundant-decls -Wswitch-default -Wswitch-enum")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES main.cpp Numbered.cpp PrintFunction.cpp)
add_executable(Synthesized_Copy_Constructor_vs_Defined ${SOURCE_FILES})