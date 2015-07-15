/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10 Jul 2015, 21:48:36:637
 *  Last updated:     10 Jul 2015, 21:45:50:553
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
 *  Exercise 13.44: Write a class named String that is a simplified version of
 *  the library string class. Your class should have at least a default
 *  constructor and a constructor that takes a pointer to a C-style string.
 *  Use an allocator to allocate memory that your String class uses.
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



#ifndef SIMPLIFIED_STRING_CLASS_STRING_H
#define SIMPLIFIED_STRING_CLASS_STRING_H


#include <memory>       // std::allocator
#include <utility>      // for std::pair

class String {
public:
    String() : firstChar(nullptr), pastlastChar(nullptr) { }
    String(const char* charPointer);

    String(const String &constructFromMe);
    String(String &&constructFromMe) noexcept;
    String& operator=(const String &copyFromMe);
    String& operator=(String &&moveFromMe) noexcept;
    ~String();

public:
    char* begin() const { return firstChar; }
    char* end() const { return pastlastChar; }
    size_t size() const { return pastlastChar - firstChar; }

private:
    // will destroy the constructed elements and deallocate the space
    void free();

// utilities used by the copy constructor, assignment operator and destructor
    // will allocated the needed space and copy a range of elements
    std::pair<char*, char*>
    allocAndCopy(const char *begin, const char *end);


    // will initialize
    void range_initializer(const char *begin, const char *end);

private:
    static std::allocator<char> alloc;      // to allocate heap memory

    char *firstChar;        // pointer to the first char in String
    char *pastlastChar;     // pointer to first unconstructed space
};


#endif //SIMPLIFIED_STRING_CLASS_STRING_H
