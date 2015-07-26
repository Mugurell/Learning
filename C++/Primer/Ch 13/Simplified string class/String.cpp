/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10 Jul 2015, 22:14:38:754
 *  Last updated:     17 Jul 2015, 13:07:08:944
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

/***********************************************************************
 * Constructors, destructors and copy/move control members
 **********************************************************************/
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
   free();
}



/**************************************************************
 * Overloaded operations
 * Members.
 **************************************************************/

char& String::operator[](std::size_t n)
{
    return firstChar[n];
}

const char& String::operator[](std::size_t n) const
{
    return firstChar[n];
}


/**************************************************************
 * Overloaded operations
 * Non - Members. Friends
 **************************************************************/

// Output operator.
// The input operator will be left for some other time.
std::ostream&
operator<<(std::ostream &os, const String &string)
{
    String buffer = string;
    while (buffer.firstChar != buffer.pastlastChar)
        os << *buffer.firstChar++;

    return os;
}


// Comparison operators
// 2 strings are equal when they have the same number of the exact same elements

bool operator==(const String &lhs, const String &rhs)
{
    bool equality = true;
    if (lhs.size() == rhs.size()) {     // if same size check each character
        for (String buff1 = lhs, buff2 = rhs;
             buff1.firstChar != buff1.pastlastChar;
             ++buff1.firstChar, ++buff2.firstChar)
        {
            if (*buff1.firstChar != *buff2.firstChar) {
                equality = false;
                break;
            }
        }
    }
    else    // if the size differs, the strings are not equal
        equality = false;

    return equality;
}

bool operator!=(const String &lhs, const String &rhs)
{
    // delegate the operator== function to do the checking
    return !(lhs == rhs);
}


// Relational operators
// We'll compare char with char and not the size first because if the shorter
// string has 1 element - 'z' and the longer string has 100 elements but the
// first is 'a', then the first string will be bigger than the second.
// Also note that one or both comparands can be nullptr. By definition, any
// string, including the empty string (""), compares greater than a null
// reference and two null references compare equal to each other.

bool operator<(const String &lhs, const String &rhs)
{
    bool is_less = false;  // will return false if both Strings are null - equal

    if (lhs.firstChar)            // if lhs is not null
    {
        if (rhs.firstChar)       // if rhs is not null
        {
            size_t count = 0;
            // max_size - max number of characters between the two Strings
            size_t max_size = lhs.size() >= rhs.size()? rhs.size() : lhs.size();

            // compare each character in both strings on the same position
            // based on it's ASCII value
            for (String left = lhs, right = rhs; ++count != max_size;
                 left.firstChar++, right.firstChar++)
            {
                if (*left.firstChar > *right.firstChar)
                {
                    is_less = false;   // first String is bigger than the second
                    break;
                }
                else if (*left.firstChar < *right.firstChar)
                {
                    is_less = true;    // first String is less-than the second
                    break;
                }
            }
            // If we iterated through all max_size characters of both Strings
            // and they all are identical,
            // but lhs has fewer elements than rhs, lhs is less-than rhs.
            is_less = (count == max_size && lhs.size() < rhs.size());
        }
        else        // if the second comparand is null, but first is valid
        {
            is_less = false;    // the first comparand is bigger
        }
    }
    else    // if the first String comparand is null
    {
        if (rhs.firstChar)      // and the second comparand is not null
            is_less = true;    // the second is bigger
    }

    return is_less;
}


// This function could've delegate the above to do the checking.
// bool operator>(const String &lhs, const String &rhs) { return rhs < lhs; }
bool operator>(const String &lhs, const String &rhs)
{
    bool is_bigger = false; // will return false if both Strings are null -equal

    if (lhs.firstChar) {         // if lhs is not null
        if (rhs.firstChar) {     // if rhs is not null
            size_t count = 0;
            // max_size - max number of characters between the two Strings
            size_t max_size = lhs.size() >= rhs.size()? rhs.size() : lhs.size();

            // compare each character in both strings on the same position
            // based on it's ASCII value
            for (String left = lhs, right = rhs; ++count != max_size;
                 left.firstChar++, right.firstChar++)
            {
                if (*left.firstChar < *right.firstChar) {
                    is_bigger = false;   // first String is less-than the second
                    break;               // we don't need to continue this loop
                }
                else if (*left.firstChar > *right.firstChar) {
                    is_bigger = true;    // first String is bigger than the 2nd
                    break;
                }
            }
            // If we iterated through all max_size characters of both Strings
            // and they all are identical,
            // but lhs has more elements than rhs, lhs is bigger than rhs.
            is_bigger = (count == max_size && lhs.size() > rhs.size());
        }
        else {       // if the second comparand is null, but first is valid
            is_bigger = true;    // the first comparand is bigger
        }
    }
    else {   // if the first String comparand is null
        if (rhs.firstChar)      // and the second comparand is not null
            is_bigger = false;    // the second is bigger
    }

    return is_bigger;
}


//  This two functions( <= and >= ) could just use the above two.
//  bool operator<=(const String &lhs, const String &rhs) { return (lhs > rhs); }
//  bool operator>=(const String &lhs, const String &rhs) { return (lhs < rhs); }
//
//  But it's more fun to think them again :-D !! Beats Sudoku ! :-)))
bool operator<=(const String &lhs, const String &rhs)
{
    bool less_equal = true;  // will return true if both Strings are null- equal

    if (lhs.firstChar) {            // if lhs is not null
        if (rhs.firstChar) {       // if rhs is not null
            size_t count = 0;
            // max_size - max number of characters between the two Strings
            size_t max_size = lhs.size() >= rhs.size()? rhs.size() : lhs.size();

            // compare each character in both strings on the same position
            // based on it's ASCII value
            for (String left = lhs, right = rhs; ++count != max_size;
                 left.firstChar++, right.firstChar++)
            {
                if (*left.firstChar > *right.firstChar) {
                    less_equal = false;   // first String is bigger than the
                    // second
                    break;
                }
                else if (*left.firstChar < *right.firstChar) {
                    less_equal = true;   // first String is less-than the second
                    break;
                }
            }
            // If we iterated through all max_size characters of both Strings
            // and they all are identical,
            // but lhs has fewer/same number of elements as rhs,
            // lhs is less or equal to rhs.
            less_equal = (count == max_size && lhs.size() <= rhs.size());
        }
        else {       // if the second comparand is null, but first is valid
            less_equal = false;    // the first comparand is bigger
        }
    }
    else {   // if the first String comparand is null
        if (rhs.firstChar)      // and the second comparand is not null
            less_equal = true;    // the second is bigger
    }

    return less_equal;
}


bool operator>=(const String &lhs, const String &rhs)
{
    bool bigger_equal = true; // will return true if both Strings are null-equal

    if (lhs.firstChar) {         // if lhs is not null
        if (rhs.firstChar) {     // if rhs is not null
            size_t count = 0;
            // max_size - max number of characters between the two Strings
            size_t max_size = lhs.size() >= rhs.size()? rhs.size() : lhs.size();

            // compare each character in both strings on the same position
            // based on it's ASCII value
            for (String left = lhs, right = rhs; ++count != max_size;
                 left.firstChar++, right.firstChar++)
            {
                if (*left.firstChar < *right.firstChar) {
                    bigger_equal = false;   // first String is less-than the
                    // second
                    break;               // we don't need to continue this loop
                }
                else if (*left.firstChar > *right.firstChar) {
                    bigger_equal = true;  // first String is bigger than the 2nd
                    break;
                }
            }
            // If we iterated through all max_size characters of both Strings
            // and they all are identical,
            // but lhs has more/same number of elements as rhs,
            // lhs is bigger or equal to rhs.
            bigger_equal = (count == max_size && lhs.size() >= rhs.size());
        }
        else {       // if the second comparand is null, but first is valid
            bigger_equal = true;    // the first comparand is bigger
        }
    }
    else {   // if the first String comparand is null
        if (rhs.firstChar)      // and the second comparand is not null
            bigger_equal = false;    // the second is bigger
    }

    return bigger_equal;
}



/**************************************************************************
 * Utilities used by the copy constructor, assignment operator, destructor
 * Private members.
 **************************************************************************/

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



/**************************************************************************
 * Analogous functions to the ones of a stl vector
 **************************************************************************/

size_t String::size() const
{ return pastlastChar - firstChar; }

char *String::end() const
{ return pastlastChar; }

char *String::begin() const
{ return firstChar; }