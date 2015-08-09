/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          luni 29 iunie 2015, 11:58:02 +0300
**  Last updated:     luni 29 iunie 2015, 22:28:40 +0300
**
**  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
**                    -Wmissing-format-attribute -Wmissing-include-dirs
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum
**
**  Execution:    ./...
**
**  Description:
**
**  By using a weak_ptr, we don’t affect the lifetime of the vector to which a
** given StrBlob points. However, we can prevent the user from attempting to
** access a vector that no longer exists.
**  Exercise 14.18: Define relational operators for your StrBlob,
** StrBlobPtr, StrVec, and String classes.
**  Exercise 14.27: Add increment and decrement operators to your
** StrBlobPtr class.
** Exercise 14.30: Add dereference and arrow operators to your StrBlobPtr class.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None ---
**
**  Notes:
**  ---
**
*******************************************************************************
******************************************************************************/

#ifndef STRBLOBPTR_STRBLOBPTR_H
#define STRBLOBPTR_STRBLOBPTR_H


#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

#include "StrBlob.h"



// StrBlobPtr throws an exception on attempts to access non-existed elements
class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator< (const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator> (const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr() : curr_(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr_(a.data_), curr_(sz) {}

    std::string& deref() const;

    std::string& operator*() const;
    std::string* operator->() const;

    // increment & decrement operators
    StrBlobPtr& operator++();
    StrBlobPtr operator++(int);
    StrBlobPtr& operator--();
    StrBlobPtr operator--(int);
private:
// check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<std::string>>
            check(std::size_t, const std::string&) const;

// store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr_;
    std::size_t curr_;      // current position within the array
};


#endif //STRBLOBPTR_STRBLOBPTR_H
