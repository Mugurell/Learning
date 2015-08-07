cmake_minimum_required(VERSION 3.2)
project(Yet_Another_Text_Querry)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow -Woverloaded-virtual \
    -Winvalid-pch -Wcast-align -Wformat=2 -Wformat-nonliteral \
    -Wmissing-declarations -Wmissing-format-attribute -Wmissing-include-dirs \
    -Wredundant-decls -Wswitch-default -Wswitch-enum")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES main.cpp AndQuery.cpp BinaryQuery.cpp GetUserInput.cpp
                 NotQuery.cpp OrQuery.cpp Query.cpp Query_base.cpp
                 QueryResult.cpp StrVec.cpp TextQuery.cpp WordQuery.cpp)
add_executable(Yet_Another_Text_Querry ${SOURCE_FILES})