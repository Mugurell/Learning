/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          09 Jul 2015, 21:29:32:436
 *  Last updated:     17 Jul 2015, 16:15:34:357
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
 *  Implementation file for the StrVec class
 *
 *  Exercise 13.43: Rewrite the free member to use for_each and a lambda
 *  in place of the for loop to destroy the elements. Which
 *  implementation do you prefer, and why?
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



#include <utility>      // for std::move
#include <algorithm>    // std::for_each()
#include <iostream>
#include <iterator>     // for std::make_move_iterator
#include <utility>      // for std::move

#include "StrVec.h"



/***********************************************************************
 * Constructors, destructor and copy/move control members
 ***********************************************************************/

// Constructor that takes an initializer list of strings, empty by default.
StrVec::StrVec(const std::initializer_list<std::string> &stringList)
{
    const std::pair<std::string*, std::string*> newData =
            allocAndCopy(stringList.begin(), stringList.end());

    firstElement = newData.first;
    // because allocAndCopy allocates space for exactly as many elements as it
    // is given, offTheEnd also points just past the last constructed element.
    firstFree = offTheEnd = newData.second;
}


// Copy/move control members
StrVec::StrVec(const StrVec &constructFromMe)
{
    const std::pair<std::string*, std::string*> newData =
            allocAndCopy(constructFromMe.begin(), constructFromMe.end());

    firstElement = newData.first;

    // because allocAndCopy allocates space for exactly as many elements as it
    // is given, offTheEnd also points just past the last constructed element.
    firstFree = offTheEnd = newData.second;
}

StrVec::StrVec(StrVec &&constructFromMe) noexcept
    : firstElement(constructFromMe.firstElement),
      firstFree(constructFromMe.firstFree),
      offTheEnd(constructFromMe.offTheEnd)
{
    // leave constructFromMe in a safe state to run the destructor on
    constructFromMe.firstElement = constructFromMe.firstFree
            = constructFromMe.offTheEnd = nullptr;
}


StrVec&
StrVec::operator=(const StrVec &copyFromMe)
{
    // call allocAndCopy to allocate exactly as many elements as in copyFromMe
    std::pair<std::string*, std::string*> data =
            allocAndCopy(copyFromMe.begin(), copyFromMe.end());
    free();
    firstElement = data.first;
    firstFree = offTheEnd = data.second;

    return *this;
}

StrVec&
StrVec::operator=(StrVec &&moveFromMe) noexcept
{
    // make sure to avoid self-assignment
    if (this != &moveFromMe) {
        free();
        firstElement = moveFromMe.firstElement;
        firstFree = moveFromMe.firstFree;
        offTheEnd = moveFromMe.offTheEnd;

        //leave the right hand operand in a state safe to run the destructor on
        moveFromMe.firstElement = moveFromMe.firstFree
                = moveFromMe.offTheEnd = nullptr;
    }
    return *this;
}

StrVec::~StrVec() {
    free();
}



/**********************************************************************
 * Overloaded operations
 * Members.
 **********************************************************************/

StrVec&
StrVec::operator=(std::initializer_list<std::string> il)
{
    std::pair<std::string*, std::string*>
            data = allocAndCopy(il.begin(), il.end());
    free();

    firstElement = data.first;
    firstFree = offTheEnd = data.second;

    return *this;
}

std::string&
StrVec::operator[](std::size_t n)
{
    return firstElement[n];
}

const std::string&
StrVec::operator[](std::size_t n) const
{
    return firstElement[n];
}



/**********************************************************************
 * Overloaded operations
 * Non - members. Friends
 **********************************************************************/

// Comparison operations.
// Two vectors of strings are equal when they have the same size
// and exactly the same strings

bool operator==(const StrVec &lhv, const StrVec &rhv)
{
    bool equality = true;

    if (lhv.size() == rhv.size()) {
        for (std::string left : lhv) {
            for (std::string right : rhv) {
                if (left != right) {
                    equality = false;
                    break;
                }
            }
        }
    }
    else
        equality = false;

    return equality;
}

bool operator!=(const StrVec &lhv, const StrVec &rhv)
{
    // delegate the operator== function to do the checking
    return !(lhv == rhv);
}


// Relational operations.
// Using the same function the stl vector uses: std::lexicographical_compare.
// Will compare each element from each vector on the same position.
// If both sequences compare equal until one of them ends, the shorter
// sequence is lexicographically less than the longer one.

bool operator<(const StrVec &lhv, const StrVec &rhv)
{
    return std::lexicographical_compare(lhv.begin(), lhv.end(),
                                        rhv.begin(), rhv.end());
}

// For the other 3 functions we'll delegate operator< to do the cheking
bool operator>(const StrVec &lhv, const StrVec &rhv)
{
    return rhv < lhv;
}

bool operator<=(const StrVec &lhv, const StrVec &rhv)
{
    return !(rhv < lhv);
}

bool operator>=(const StrVec &lhv, const StrVec &rhv)
{
    return !(lhv < rhv);
}



/**************************************************************************
 * Utilities used by the copy constructor, assignment operator, destructor
 * Private members.
 **************************************************************************/

// Because the memory an allocator allocates is unconstructed, we'll use the
// allocator's construct member to create objects in that space when we need
// to add an element. Similarly, when we remove an element, we'll use the
// destroy member to destroy the element.
std::allocator<std::string> StrVec::alloc;


// will set the StrVec's capacity ro exactly the required size
void StrVec::resize(const size_t &newSize)
{
    // if newSize is bigger than the current capacity
    // we'll just call reserve to increase it
    if (newSize > capacity())
        reserve(newSize);

    // If newSize is smaller than the capacity reduce the capacity to newSize.
    // If newSize is smaller than the current size, we'll assume that the
    // user also wants to deallocate some memory so we'll move elements from
    // the current vector up to newSize to a newly constructed one.
    if (size() > newSize || capacity() > newSize) {
        // allocate newSize heap space for a new vector
        std::string *newMemory = alloc.allocate(newSize);

        // move data from the old heap memory to the new one
        std::string *dest = newMemory;
        std::string *curr = firstElement;
        for (size_t i = 0; i < newSize; ++i)
            alloc.construct(dest++, std::move(*curr++));

        // free the old heap memory once we've moved the data from it
        //std::cout << "**Before free, size() - " << size() << "\n\n";
        free();
        //std::cout << "**After free, size() - " << size() << "\n\n";

        // update our StrVec's members to newMemory ones
        firstElement = newMemory;
        firstFree = offTheEnd = firstElement + newSize;
    }
}

// A call to reserve changes the capacity of the vector only if the requested
// space exceeds the current capacity.
void StrVec::reserve(const size_t &newSize)
{
    // First check if our 'vector' has any elements.
    // If the 'vector' is empty, allocate it the required space and finish.
    if (size() == 0 && newSize > capacity()) {
    // allocate the required heap space
        std::string *newMemory = alloc.allocate(newSize);

    // initialize this StrVec's elements
        firstElement = newMemory;
        firstFree = offTheEnd = firstElement + newSize;
    }
    // If it has elements they must be copied in the new heap space
    if (newSize > capacity()) {
    // allocate the required heap space
        std::string *newMemory = alloc.allocate(newSize);

    // move data from the old memory to the newly allocated one
        // pointer to the free position in the newly allocated memory
        std::string *dest = newMemory;
        // pointer to the current element we're working with from the old memory
        std::string *curr = firstElement;

        size_t oldSize = size();
        for (size_t i = 0; i != oldSize; i++) {
            // because we're using the move constructor, the memory managed by
            // those strings will not be copied. Instead, each string we
            // construct will take ownership of the memory from the string to
            // which elem points.
            alloc.construct(dest++, std::move(*curr++));
        }

    // free the old heap memory
        free();

    // initialize this StrVec's members with newMemory pointers
        firstElement = newMemory;
        firstFree = dest;
        offTheEnd = firstElement + newSize;
    }
}


void StrVec::reallocate()
{
    // we'll double the capacity of StrVec each time we reallocate
    // if StrVec is empty, we allocate room for one element
    auto newCapacity = size() ? 2 * size() : 1;
    // allocate new memory
    std::string *newData = alloc.allocate(newCapacity);

///////// Will use uninitialized_copy as an easier alternative to this ///////
//
//    // move the data from the old memory to the new
//    std::string *dest = newData;    // points to the next free position
//                                    // in the new array
//    auto elem = firstElement;      // points to  next element in the old array
//    size_t currentSize = size();
//    for (size_t i = 0; i != currentSize; i++) {
//        // because we're using the move constructor,memory managed by those
//        // strings will not be copied. Instead, each string we construct will
//        // take ownership of the memory from the string to which elem points.
//        alloc.construct(dest++, std::move(*elem++));
//    }
//////////////////////////////////////////////////////////////////////////////

    // "move" the elements using std::uninitialized_copy and move iterators
    // (which yield rvalue references)
    // uninitialized_copy will return an iterator to the last element in newData
    std::string *last = std::uninitialized_copy
                           (std::make_move_iterator(begin()),  // begin iterator
                            std::make_move_iterator(end()),    // end iterator
                            newData); // output iterator to the initial position

    free();     // free the old space once we've moved the elements

    // update our data structure to point to the new elements
    firstElement = newData;
    firstFree = last;
    offTheEnd = firstElement + newCapacity;
}


// If there isn't room for another element, chk_n_alloc will call reallocate
// to get more space.
void StrVec::checkAndAllocate()
{
    if (size() == capacity())
        reallocate();
}


// The allocAndCopy member will allocate enough storage to hold its given range
// of elements, and will copy those elements into the newly allocated space.
// This function returns a pair  of pointers, pointing to the beginning of the
// new space and just past the last element it copied:
std::pair<std::string *, std::string *>
StrVec::allocAndCopy(const std::string *begin, const std::string *end)
{
    // allocate space to hold as many elements as there are in the range
    std::string* data = alloc.allocate(end - begin);

    // initialize and return a pair constructed from data and
    // the value returned by data and uninitializedCopy
    // uninitialized_copy copies elements from the input range into
    // unconstructed, raw memory denoted by the iterator data
    return {data, std::uninitialized_copy(begin, end, data)};
}


// The free member has two responsibilities: It must destroy the elements and
// then deallocate the space that this StrVec itself allocated. The for loop
// calls the allocator member destroy in reverse order, starting with the last
// constructed element and finishing with the first:
void StrVec::free()
{
    // may not pass deallocate on a null pointer,
    // if firstElement is null, there's no work to do
    if (firstElement) {
        // destroy the old elements in reverse order
        while (firstFree != firstElement) {
            alloc.destroy(--firstFree);
        }

// Implementation as for Ex 13.43
//        std::for_each(firstElement, firstFree,
//            [] (std::string &curr) { alloc.destroy(&curr);} );

        alloc.deallocate(firstElement, offTheEnd - firstElement);
    }

}


/**************************************************************************
 * Analogous functions to the ones of a stl vector
 **************************************************************************/

// The push_back function calls checkAndAllocate to ensure that there is room
// for an element. If necessary, checkAndAllocate will call reallocate.
// When checkAndAllocate returns, push_back knows that there is room for the new
// element. It asks its allocator member to construct a new last element.
void StrVec::push_back(const std::string &string)
{
    checkAndAllocate();     // ensure that there is room for another element

    // construct a copy of string in the element to which firstFree points
    alloc.construct(firstFree++, string);
}

void StrVec::push_back(std::string &&string) {
    checkAndAllocate();     // reallocate the StrVec if necessary
    alloc.construct(firstFree++, std::move(string));
}

std::string *StrVec::end() const
{ return firstFree; }

std::string *StrVec::begin() const
{ return firstElement; }

size_t StrVec::capacity() const
{ return offTheEnd - firstElement; }

size_t StrVec::size() const
{ return firstFree - firstElement; }
