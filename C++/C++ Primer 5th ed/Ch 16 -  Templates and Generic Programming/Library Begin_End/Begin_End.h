/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10-Aug-15, 05:31 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Exercise 16.6: How do you think the library begin and end functions that
 *  take an array argument work? Define your own versions of these functions.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  "Authors of templates should provide a header that contains the template
 *  definition along with declarations for all the names used in the class
 *  template or in the definitions of its members. Users of the template must
 *  include the header for the template and for any types used to instantiate
 *  that template."
 *  "Template programs should try to minimize the number of requirements
 *  placed on the argument types."
 *  Make sure the only place that includes <X>.tpp is the last line in <X>.h
 *
 *  std::begin  is a template function that takes a reference to an array.It
 *  returns this reference as the iterator pointing to the first element in
 *  this array.
 *  std::end is a template function that takes a reference to an array and
 *  capture the size. It return this reference plus the size as the iterator
 *  pointing to one past last element.
 *
********************************************************************************
*******************************************************************************/



#ifndef LIBRARY_BEGIN___END_BEGIN_END_H
#define LIBRARY_BEGIN___END_BEGIN_END_H


#include <cstddef>      // std::size_t


// versions of begin() and end() for regular arrays
template <typename T, std::size_t N>
T* Begin(T (&arr)[N]);

template <typename T, std::size_t N>
T* End(T (&arr)[N]);


// versions of begin() and end() for stl containers
template<typename Container>
auto Begin(Container &cont) -> decltype(cont.begin());

template<typename Container>
auto End(Container &cont) -> decltype(cont.end());



#include "Begin_End.tpp"


#endif //LIBRARY_BEGIN___END_BEGIN_END_H
