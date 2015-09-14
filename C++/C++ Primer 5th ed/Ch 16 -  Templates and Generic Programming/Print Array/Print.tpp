/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10-Aug-15, 03:55 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Implementation file for the templated Print function.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  Because the file is a *.tpp file (not *.cpp) it should not be included by
 *  other build system operations.
 *  Make sure the only place that includes <X>.tpp is the last line in <X>.h
 *
********************************************************************************
*******************************************************************************/


#include <iostream>


template<typename T, unsigned Size>
inline void Print(const T (&array)[Size])
{
    unsigned count = 0;
    unsigned size = Size;

    while (size-- != 0)
        std::cout << array[count++];
}


template<typename T>
inline void Print2(const T &array)
{
    for (const auto each : array)
        std::cout << each;
}