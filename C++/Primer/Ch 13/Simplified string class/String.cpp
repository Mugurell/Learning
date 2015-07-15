/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10 Jul 2015, 22:14:38:754
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
 *  Implementation file for the String class.
 *  Exercise 13.50: Put print statements in the move operations in your
 *  String class and rerun the program that used a vector<String> to see
 *  when the copies are avoided.

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



#include <algorithm>
#include <iostream>

#include "String.h"


std::allocator<char> String::alloc;


String::String(const char *charPointer)
{
    // create a new c style string to regular chars (- not const) to work with
    char *chars = const_cast<char*>(charPointer);

    // increment it so that it points to the last char
    while (*chars) ++chars;

    // send them as a range (first, one past end) to range_initializer
    range_initializer(charPointer, ++chars);
}

String::String(const String &constructFromMe)
{
    range_initializer(constructFromMe.firstChar, constructFromMe.end());
    std::cout << "\n**Copy constructor used.**\n";
}

String::String(String &&constructFromMe) noexcept
    : firstChar(constructFromMe.firstChar),
      pastlastChar(constructFromMe.firstChar)
{
    // make sure to leave the right hand operator in a safe state
    constructFromMe.firstChar = constructFromMe.pastlastChar = nullptr;
    std::cout << "\n**Move constructor used**\n";
}

String& String::operator=(String &&moveFromMe) noexcept
{
    if (this != &moveFromMe) {
        free();
        firstChar = moveFromMe.firstChar;
        pastlastChar = moveFromMe.pastlastChar;

        moveFromMe.firstChar = moveFromMe.pastlastChar = nullptr;
    }

    std::cout << "\n**Move assignment operator used**\n";
    return *this;
}


String& String::operator=(const String &copyFromMe)
{
    // To properly handle self-assignement we'll initialize a new String
    // from the received argument before we destruct *this.
    std::pair<char*, char*> newCopy =
        allocAndCopy(copyFromMe.begin(), copyFromMe.pastlastChar);

    // now it's safe to destruct *this
    free();

    // initialize our members with the new range
    firstChar = newCopy.first;
    pastlastChar = newCopy.second;

    std::cout << "\n**Copy assignement operator used.**\n";

    return *this;
}

String::~String()
{
   // free();
}


void String::free()
{
    // if our string contains at least one character
    if (firstChar) {
        // destroy all characters
//        for (auto p = pastlastChar; p != firstChar; /* empty */)
//            alloc.destroy(--p);
        std::for_each(firstChar, pastlastChar,
            [this] (char &c) { alloc.destroy(&c); } );
        // and return the memory to freestore

        alloc.deallocate(firstChar, pastlastChar - firstChar);
    }
}

// will initialize out 2 members with begin and one past the end pointers
// to an array of pointers to chars - a string.
void String::range_initializer(const char *begin, const char *end)
{
    std::pair<char*, char*> newString = allocAndCopy(begin, end);
    firstChar = newString.first;
    pastlastChar = newString.second;
}


std::pair<char*, char*>
String::allocAndCopy(const char *begin, const char *end)
{
    // allocate exactly the needed space to accomodate the chars in range
    char *string = alloc.allocate(end - begin);

    // uninitialized_copy copies elements from the input range into
    // unconstructed, raw memory denoted by the iterator data
    // so we'll return basically a string
    return {string, std::uninitialized_copy(begin, end, string)};
}