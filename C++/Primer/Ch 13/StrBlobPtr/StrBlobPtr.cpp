/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          18 Jul 2015, 09:29:51:211
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Execution:    ./...
 *
 *  Description:
 *  Implementation file for StrBlobPtr class.
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
*******************************************************************************
******************************************************************************/



#include "StrBlobPtr.h"


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
// if curr_ already points past the end of the container, can't increment it
    check(curr_, "increment past end of StrBlobPtr");
    ++curr_;        // advance the current state
    return *this;
}