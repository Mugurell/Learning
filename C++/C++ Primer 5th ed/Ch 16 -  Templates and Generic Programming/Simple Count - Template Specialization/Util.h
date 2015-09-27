/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          27-Sep-15, 04:41 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *   Exercise 16.63: Define a function template to count the number of
 *  occurrences of a given value in a vector. Test your program by passing it a
 *  vector of doubles, a vector of ints, and a vector of strings.
 *   Exercise 16.64: Write a specialized version of the template from the
 *  previous exercise to handle vector<const char*> and a program that
 *  uses this specialization.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  --- 
 *
********************************************************************************
*******************************************************************************/


#ifndef SIMPLE_COUNT_TEMPLATE_SPECIALIZATION_UTIL_H
#define SIMPLE_COUNT_TEMPLATE_SPECIALIZATION_UTIL_H


#include <vector>
#include <vector>


template <typename T>
size_t count(const std::vector<T> &v, const T &value);

template<>
size_t count(const std::vector<int> &v, const int &value);

template<>
size_t count(const std::vector<double> &v, const double &value);

template<>
size_t count(const std::vector<std::string> &v, const std::string &value);

template<>
size_t count(const std::vector<const char*> &v, const char* const &value);


#include "Util.tpp"     // include the implementation file for this templates


#endif //SIMPLE_COUNT_TEMPLATE_SPECIALIZATION_UTIL_H
