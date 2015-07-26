/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10 Jul 2015, 21:48:36:637
 *  Last updated:     17 Jul 2015, 14:07:26:976
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
 *  Exercise 14.7: Define an output operator for you String class.
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
 *  From what I've read on SO it seems that it is a needed best practice to
 *  define member functions only in implementation files, not the header.
 *  The headers should be free of any implementation except rare cases of
 *  trivial inline functions (eg getters/setters) and unless they're templates.
 *  This is valuable in >= medium projects where it will avoid rebuilding all
 *  source files using that header.
 *  Besides that, exposing implementation details is contrary to OOP.
 *
*******************************************************************************
******************************************************************************/



#ifndef SIMPLIFIED_STRING_CLASS_STRING_H
#define SIMPLIFIED_STRING_CLASS_STRING_H


#include <memory>       // std::allocator
#include <utility>      // for std::pair
#include <string>
#include <vector>

class String {
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend bool operator==(const String &lhs, const String &rhs);
    friend bool operator!=(const String &lhs, const String &rhs);

    // A string is less-than the other when an element in the same position
    // has a lower ASCII value than the other, or, if both strings compared have
    // the same elements upto where one ends and the other one continues.
    friend bool operator<(const String &lhs, const String &rhs);
    friend bool operator<=(const String &lhs, const String &rhs);
    friend bool operator>(const String &lhs, const String &rhs);
    friend bool operator>=(const String &lhs, const String &rhs);

public:
    String() : firstChar(nullptr), pastlastChar(nullptr) { }
    String(const char* charPointer);

    String(const String &constructFromMe);
    String(String &&constructFromMe) noexcept;
    String& operator=(const String &copyFromMe);
    String& operator=(String &&moveFromMe) noexcept;
    ~String();

    char& operator[](std::size_t n);
    const char& operator[](std::size_t n) const;

public:
    char * begin() const;
    char * end() const;
    size_t size() const;

private:
    // will destroy the constructed elements and deallocate the space
    void free();

// utilities used by the copy constructor, assignment operator and destructor
    // will allocated the needed space and copy a range of elements
    std::pair<char*, char*> allocAndCopy(const char *begin, const char *end);
    // will initialize our String with the chars from the given range
    void range_initializer(const char *begin, const char *end);

private:
    static std::allocator<char> alloc;      // to allocate heap memory

    char *firstChar;        // pointer to the first char in String
    char *pastlastChar;     // pointer to first unconstructed space
};


#endif //SIMPLIFIED_STRING_CLASS_STRING_H
