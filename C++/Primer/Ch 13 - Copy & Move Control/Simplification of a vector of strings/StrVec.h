/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          09 Jul 2015, 21:29:38:349
 *  Last updated:     17 Jul 2015, 16:15:39:956
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
 *  Exercise 14.16: Define equality and inequality operators for your StrBlob,
 *  StrBlobPtr, StrVec, and String classes.
 *  Exercise 14.18: Define relational operators for your StrBlob,
 *  StrBlobPtr, StrVec, and String classes.
 *  Exercise 14.26: Define subscript operators for your StrVec, String,
 *  StrBlob, and StrBlobPtr classes.
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
    friend bool operator==(const StrVec &lhv, const StrVec &rhv);
    friend bool operator!=(const StrVec &lhv, const StrVec &rhv);
    friend bool operator<(const StrVec &lhv, const StrVec &rhv);
    friend bool operator>(const StrVec &lhv, const StrVec &rhv);
    friend bool operator<=(const StrVec &lhv, const StrVec &rhv);
    friend bool operator>=(const StrVec &lhv, const StrVec &rhv);

public:
    StrVec()    // the allocator member will be default initialized
        : firstElement(nullptr), firstFree(nullptr), offTheEnd(nullptr) { }

    StrVec(const std::initializer_list<std::string> &stringList);

    StrVec(const StrVec &constructFromMe);
    StrVec& operator=(const StrVec &copyFromMe);
    StrVec(StrVec &&constructFromMe) noexcept;
    StrVec& operator=(StrVec &&moveFromMe) noexcept;
    ~StrVec();

    // overloaded assignment operator
    StrVec& operator=(std::initializer_list<std::string> il);
    const std::string& operator[](std::size_t n) const;
    std::string& operator[](std::size_t n);


// some public methods analogous to the ones of a std::vector
    // used to construct another element at *firstFree
    void push_back(const std::string&);     // copy the element
    void push_back(std::string &&);         // move the element
    size_t size() const;
    size_t capacity() const;
    // allocate space for at least n elements - newSize.
    void reserve(const size_t &newSize);
    // resize the container so that it contains exactly the requested elements
    void resize(const size_t &newSize);
    std::string * begin() const;
    std::string * end() const;

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

private:
    // To try and mimic std::vector's approach to allocate memory (preallocate
    // contiguous space, etc) we'll use an allocator to obtain raw memory.
    static std::allocator<std::string> alloc;

    std::string *firstElement; // pointer to the first element in the array
    std::string *firstFree;    // pointer to the first free element in the array
    std::string *offTheEnd;    // pointer to one past the end of the array
};



#endif //SIMPLIFICATION_OF_A_VECTOR_OF_STRINGS_STRVEC_H
