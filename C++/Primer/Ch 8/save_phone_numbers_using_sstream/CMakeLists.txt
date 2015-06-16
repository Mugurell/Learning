cmake_minimum_required(VERSION 3.2)
project(8_3_save_phone_numbers_using_sstream)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow -Woverloaded-virtual \
    -Winvalid-pch -Wcast-align -Wformat=2 -Wformat-nonliteral \
    -Wmissing-declarations -Wmissing-format-attribute -Wmissing-include-dirs \
    -Wredundant-decls -Wswitch-default -Wswitch-enum")

set(SOURCE_FILES FileChecks.cpp PersonInfo.cpp main.cpp)

add_executable(read_format_save_contacts ${SOURCE_FILES})
