cmake_minimum_required(VERSION 3.2)
project(Book_Sales_Using_Derivate_Classes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow -Woverloaded-virtual \
    -Winvalid-pch -Wcast-align -Wformat=2 -Wformat-nonliteral \
    -Wmissing-declarations -Wmissing-format-attribute -Wmissing-include-dirs \
    -Wredundant-decls -Wswitch-default -Wswitch-enum")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES main.cpp Quote.cpp Discounts.cpp Functions.cpp
                          Person.cpp Basket.cpp)
add_executable(Book_Sales_Using_Derivate_Classes ${SOURCE_FILES})