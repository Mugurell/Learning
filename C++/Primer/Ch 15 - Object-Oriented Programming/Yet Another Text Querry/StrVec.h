/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          09 Jul 2015, 21:29:38:349
 *  Last updated:     10 Jul 2015, 17:53:26:095
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
 *  Simplified implementation of the memory allocation strategy for a
 *  vector-like class.
 *  Exercise 13.39: Write your own version of StrVec, including versions of
 *  reserve, capacity, and resize.
 *  Exercise 13.40: Add a constructor that takes an initializer_list<string> to
 *  your StrVec class.
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



#ifndef SIMPLIFICATION_OF_A_VECTOR_OF_STRINGS_STRVEC_H
#define SIMPLIFICATION_OF_A_VECTOR_OF_STRINGS_STRVEC_H

#include <string>
#include <memory>       // for std::allocator
#include <initializer_list>



class StrVec {
public:
    typedef size_t size_type;

    StrVec()    // the allocator member will be default initialized
        : firstElement(nullptr), firstFree(nullptr), offTheEnd(nullptr) { }

    StrVec(const std::initializer_list<std::string> &stringList);

    StrVec(const StrVec &constructFromMe);
    StrVec& operator=(const StrVec &copyFromMe);
    ~StrVec();

// some public methods analogous to the ones of a std::vector
    // used to construct another element at *firstFree
    void push_back(const std::string&);

    // returns the number of elements actually in use
    size_t size() const { return firstFree - firstElement; }

    // returns the number of elements that the StrVec can hold
    size_t capacity() const { return offTheEnd - firstElement; }

    // allocate space for at least n elements - newSize.
    void reserve(const size_t &newSize);

    // resize the container so that it contains exactly the requested elements
    void resize(const size_t &newSize);

    // returns a pointer to the first constructed element
    std::string *begin() const { return firstElement; }

    // returns a pointer to one past the last constructed element
    std::string *end() const { return firstFree; }

private:
    // will ensure that there is room to add at least one element
    void checkAndAllocate();

// utilities used by the copy constructor, assignment operator, destructor
    // will allocate space and copy a given range of elements
    std::pair<std::string*, std::string*> allocAndCopy
            (const std::string *begin, const std::string *end);

    // will destroy the constructed elements and deallocate the space.
    void free();

    // will reallocate the StrVec when it runs out of space.
    void reallocate();

// member variables
    // To try and mimic std::vector's approach to allocate memory (preallocate
    // contiguous space, etc) we'll use an allocator to obtain raw memory.
    static std::allocator<std::string> alloc;

    std::string *firstElement; // pointer to the first element in the array
    std::string *firstFree;    // pointer to the first free element in the array
    std::string *offTheEnd;    // pointer to one past the end of the array
};


#endif //SIMPLIFICATION_OF_A_VECTOR_OF_STRINGS_STRVEC_H
