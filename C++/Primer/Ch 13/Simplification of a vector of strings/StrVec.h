/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          09 Jul 2015, 21:29:38:349
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
 *  Simplified implementation of the memory allocation strategy for a
 *  vector-like class.
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



#include <iostream>



#ifndef SIMPLIFICATION_OF_A_VECTOR_OF_STRINGS_STRVEC_H
#define SIMPLIFICATION_OF_A_VECTOR_OF_STRINGS_STRVEC_H


class StrVec {
public:
    StrVec()    // the allocator member will be default initialized
        : firstElement(nullptr), firstFree(nullptr), offTheEnd(nullptr) { }

    StrVec(const StrVec &constructFromMe);
    StrVec& operator=(const StrVec &copyFromMe);
    ~StrVec();

// some public methods analoguous to the ones of a std::vector
    void push_back(const std::string&);
    size_t size() const { return firstFree - firstElement; }
    size_t capacity() const { return offTheEnd - firstFree; }
    std::string *begin() const { return firstElement; }
    std::string *end() { return firstFree; }

private:
    // will ensure that there is room to add at least one element
    void checkAndAllocate();

// utilities used by the copy constructor, assignment operator, destructor
    // will allocate space and copy a given range of elements
    std::pair<std::string*, std::string*> allocAndCopy
            (const std::string*, const std::string*);

    // will destroy the constructed elements and deallocate the space.
    void free();

    // will reallocate the StrVec when it runs out of space.
    void reallocate();

// member variables
    // To try and mimic std::vector's approach to allocate memory (preallocate
    // contiguous space, etc) we’ll use an allocator to obtain raw memory.
    static std::allocator<std::string> alloc;

    std::string *firstElement; // pointer to the first element in the array
    std::string *firstFree;    // pointer to the first free element in the array
    std::string *offTheEnd;    // pointer to one past the end of the array

};


#endif //SIMPLIFICATION_OF_A_VECTOR_OF_STRINGS_STRVEC_H
