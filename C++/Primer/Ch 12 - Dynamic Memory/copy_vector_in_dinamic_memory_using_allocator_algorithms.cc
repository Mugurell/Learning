/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 2 iulie 2015, 20:59:51 +0300
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
**  Assuming we have a vector of ints that we want to copy into dynamic memory,
**  we’ll allocate memory for twice as many ints as are in the vector. 
**  We’ll construct the first half of the newly allocated memory by copying
**  elements from the original vector. We’ll construct elements in the second 
**  half by filling them with a given value
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None ---  
**
**  Notes:
**  Like the copy algorithm, uninitialized_copy takes three iterators.
**  The first two denote an input sequence and the third denotes the 
**  destination into which those elements will be copied. The destination 
**  iterator passed to uninitialized_copy must denote unconstructed memory.
**  Unlike copy, uninitialized_copy constructs elements in its destination.
**
**  Like copy, uninitialized_copy returns its (incremented) destination
**  iterator.
**  Thus, a call to uninitialized_copy returns a pointer positioned one element
**  past the last constructed element. In this example, we store that pointer
**  in q, which we pass to uninitialized_fill_n. 
**  This function, like fill_n, takes a pointer to a destination, a count, and 
**  a value. It will construct the given number of objects from the given value
**  at locations starting at the given destination.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <memory>       // allocator functions, among other goodies
#include <algorithm>    // for_each   


int main()
{
    std::vector<int> intVector{1, 2, 3, 4, 5, 6, 7};
    std::cout << "\nLet's assume we have a nice little vector of ints:\n\t";
    std::for_each(intVector.cbegin(), intVector.cend(),
                    [] (const int &nr) { std::cout << nr << ' '; });
    std::cout << "\nLet's copy that into free store and add some bonus ints\n";

    // define an allocator object that can allocate heap for int objects
    std::allocator<int> alloc;

    // allocate twice as many elements to a new pointer of dinamic ints
    auto dinamicIntsPtr = alloc.allocate(intVector.size() * 2);

    // construct elements starting from the begining of intVector as copies
    // of the ones in intVector
    auto anotherPointer = 
        std::uninitialized_copy(intVector.begin(), intVector.end(), 
                                dinamicIntsPtr);

    // initialize the remaining elements with a preset value, let's say 9
    std::uninitialized_fill_n(anotherPointer, intVector.size(), 9);

    // This is very important!
    // If not for this, dinamicIntsPtr would be incremented in this loop
    // and then sent like so to alloc.deallocate 
    // => munmap_chunk(): invalid pointer
    auto backup = dinamicIntsPtr;
    
    std::cout << "\nAnd we'll have...\n\t";
    for (int count = 0, limit = intVector.size() * 2; count++ != limit;) {
        std::cout << *dinamicIntsPtr++ << ' ';

    }
    std::cout << "\n\nPretty cool, huh?\n" << std::endl;

    // DON'T FORGET to destroy the dinamic objects and return the allocated
    // space on the heap!
    dinamicIntsPtr = backup;
    alloc.destroy(dinamicIntsPtr);
    alloc.deallocate(dinamicIntsPtr, intVector.size() * 2);

    return 0;
}