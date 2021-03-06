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
 *  Exercise 16.24: Add a constructor that takes two iterators to your Blob
 *  template.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  If a member function isn�t used, it is not instantiated.
 *  The fact that members are instantiated only if we use them lets us
 *  instantiate a class with a type that may not meet the requirements for some
 *  of the template�s operations
 *
********************************************************************************
*******************************************************************************/



#ifndef BLOB_BLOB_H
#define BLOB_BLOB_H


#include <initializer_list>
#include <memory>               // std::shared_ptr
#include <utility>              // std::move
#include <vector>


// forward declarations
template <typename> class BlobPtr;
template <typename> class Blob;     // needed for parameters in operator==
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);


template<typename T>
class Blob {
    // The friend declarations use Blob�s template parameter as their own.
    // Thus, the friendship is restricted to those instantiations of BlobPtr
    // and the equality operator that are instantiated with the same type.
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    // constructors
    Blob();
    Blob(std::initializer_list<T> il);
    // initialize the underlying vector of the data shared_ptr
    // from a pair of iterators
    Blob(T *it1, T *it2);

    // number of elements in the Blob
    size_type size()  const { return data->size(); }
    bool     empty() const { return data->empty(); }

    // and and remove elements
    void push_back(const T &t)  const { data->push_back(t); }
    // move version
    void push_back(const T &&t) const { data->push_back(std::move(t)); }
    void pop_back();

    // element access
    T& back();
    T& operator[](size_type i);

    const T& back() const;
    const T& operator[](size_type i) const;

private:
    std::shared_ptr<std::vector<T>> data;
    // throws msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};


#include "Blob.tpp"


#endif //BLOB_BLOB_H
