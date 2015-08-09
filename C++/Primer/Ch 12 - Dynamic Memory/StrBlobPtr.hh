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
**  --- This is a description of what the program does ---
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  --- You can write here the execution command & the expected result --- 
**
**  Notes:
**  --- Anything that stands out ---
**  --- Or needs to be treated with special attention ---
**
*******************************************************************************
******************************************************************************/

#ifndef STRBLOBPTR_
#define STRBLOBPTR_     1


#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>


// StrBlobPtr throws an exception on attempts to access non-existed elements
class StrBlobPtr {
public:
    StrBlobPtr() : curr_(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr_(a.data_), curr_(sz) {}

    std::string& deref() const;
    StrBlobPtr& incr();     // prefix version
private:
// check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;

// store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr_;
    std::size_t curr_;      // current position within the array
};


/*
** Because a weak_ptr does not participate in the reference count of its
** corresponding shared_ptr, the vector to which this StrBlobPtr points might
** have been deleted. If the vector is gone, lock will return a null pointer.
** In this case, any reference to the vector will fail, so we throw an
** exception. Otherwise, check verifies its given index.
** If that value is okay, check returns the shared_ptr it obtained from lock.
*/
std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr_.lock();     // is the vector still around?
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i > ret->size())
        throw std::out_of_range(msg);

    return ret;     // otherwise return a shared_ptr to the vector
}


/*
** If check succeeds, p is a shared_ptr to the vector to which this StrBlobPtr
** points. The expression (*p)[curr_] dereferences that shared_ptr to get the
** vector and uses the subscript operator to fetch and return the element at
** curr_.
*/
std::string&
StrBlobPtr::deref() const {
    auto p = check(curr_, "dereference past end");
    return (*p)[curr_];      // (*p) is the vector to which the object points
}


/*
** prefix() will return a reference to the incremented object
*/
StrBlobPtr&
StrBlobPtr::incr() {
// if curr_ allready points past the end of the container, can't increment it
    check(curr_, "increment past end of StrBlobPtr");
    ++curr_;        // advance the current state
    return *this;
}



#endif STRBLOBPTR_