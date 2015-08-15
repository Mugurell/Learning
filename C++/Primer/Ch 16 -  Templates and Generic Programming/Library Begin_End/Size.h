/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10-Aug-15, 07:21 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Exercise 16.7: Write a constexpr template that returns the size of a given
 *  array.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  "Constexpr's primary function is to extend the range of what can be computed
 *  at compile time, making such computation type safe." - Stroustrup
 *
********************************************************************************
*******************************************************************************/



#ifndef LIBRARY_BEGIN_END_SIZE_H
#define LIBRARY_BEGIN_END_SIZE_H



#include <cstddef>      // std::size_t


// return the size of a plain old array
template<typename T, std::size_t N>
constexpr std::size_t Size(T (&arr)[N]);


// return the size of a stl array, or any library container...
template<typename Container>
constexpr std::size_t Size(const Container &cont);


#include "Size.tpp"

#endif //LIBRARY_BEGIN_END_SIZE_H
