/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 7 iulie 2015, 22:12:38 +0300
**  Last updated:           ---
**
**  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**                    -Wmissing-format-attribute -Wmissing-include-dirs  
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
**
**  Execution:    ./...
**
**  Description:
**  Exercise 13.27: Define your own reference-counted version of HasPtr.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None ---  
**
**  Notes:
**  The easiest way to make a class act like a pointer is to use shared_ptrs to
**  manage the resources in the class. Copying (or assigning) a shared_ptr 
**  copies (assigns) the pointer to which the shared_ptr points. The shared_ptr
**  class itself keeps track of how many users are sharing the pointed-to 
**  object. When there are nomore users, the shared_ptr class takes care of 
**  freeing the resource.
** 
**  However, sometimes we want to manage a resource directly. In such cases, it
**  can be useful to use a reference count (§ 12.1.1, p. 452). To show how 
**  reference counting works, in this implementation we'll do our own counting.
**
*******************************************************************************
******************************************************************************/


#include <string>
#include <new>
#include <cstddef>      // for size_t;


class HasPtr {
public:
    HasPtr(const std::string &s = "")
        : ps(new std::string(s)), i(0), count(new std::size_t(1)) { }

// copy constructor (rule of 3/5)
    HasPtr(const HasPtr &received_)
        : ps(received_.ps), i(received_.i) count(received_.count) { ++*count; }

// copy assignment operator (rule of 3/5)
    HasPtr& operator=(const HasPtr &received);

// destructor needed because ps points to heap allocated memory
    ~HasPtr();

private:
    std::string *ps;
    int i;
    std::size_t *count;
};


// The destructor cannot unconditionally delete ps—there might be other objects
// pointing to that memory. Instead, the destructor decrements the reference 
// count, indicating that one less object shares the string. If the counter 
// goes to zero, then the destructor frees the memory to which both ps and use 
// are pointing:
inline HasPtr::~HasPtr() {
    if (--*count == 0) {    // if the reference goes to 0
        delete ps;          // delete the string
        delete count;       // detele the counter
    }
}


// The copy-assignment operator, as usual, does the work common to the copy
// constructor and to the destructor. That is, the assignment operator must 
// increment the counter of the right-hand operand (i.e., the work of the copy
// constructor) and decrement the counter of the left-hand operand, deleting 
// the memory used if appropriate (i.e., the work of the destructor).
// Also, as usual, the operator must handle self-assignment. We do so by 
// incrementing the count in rhs before decrementing the count in the left-hand
// object. That way if both objects are the same, the counter will have been 
// incremented before we check to see if ps (and use) should be deleted:
inline HasPtr&
HasPtr::operator=(const HasPtr &received) {
    ++*rhs.use;         // increment the use count of the right-hand operand
    if (--*use == 0) {     // then decrement this object's counter 
        delete ps;         // if no other users,
        delete count;      // free this object's allocated members
    }
    ps(received.ps);        // copy the data from received into this object
    i(received.i);
    count(received.count);

    return *this;           // return this object
}
