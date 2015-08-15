/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          11-Aug-15, 01:26 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Implementation file for the templated Blob class.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  When the compiler instantiates a class from our Blob template, it rewrites
 *  the Blob template, replacing each instance of the template parameter T by
 *  the given template argument.
 *  To define a type from our Blob template, we must provide the element type:
 *      Blob<int> c1;           // empty Blob templated to use int
 *      Blob<std::string>c2;    // empty Blob templated to use std::string
 *  When implemented, our functions must be defined in the scope of Blob<T>.
 *
********************************************************************************
*******************************************************************************/



#include <stdexcept>
#include <memory>
#include <vector>

// constructors
// Allocates an empty vector and stores the pointer to that vector in data.
template <typename T>
inline Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) { }

// Use type parameter T as the element type for its initializer_list parameter.
template <typename T>
inline Blob<T>::Blob(std::initializer_list<T> il) :
        data(std::make_shared<std::vector<T>>(il)) { }


// helper function used to check if the subscript (i) is valid for our Blob
template <typename T>
inline void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}


// element access
template <typename T>
inline T& Blob<T>::back()
{
    check(0, "back on empty Blob?");
    return data->back();
}

template <typename T>
inline const T& Blob<T>::back() const
{
    check(0, "back on empty Blob?");
    return data->back;
}

template <typename T>
inline T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range!");
    return data->at(i);
}

template <typename T>
inline const T& Blob<T>::operator[](size_type i) const
{
    check(i, "subscript out of range!");
    return data->at(i);
}


// remove last element in our BLob
template <typename T>
inline void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob?");
    data->pop_back();
}




