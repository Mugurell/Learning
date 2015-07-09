/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          09 Jul 2015, 21:29:32:436
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
 *  --- This is a description of what the program does ---
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


#include "StrVec.h"



// Because the memory an allocator allocates is unconstructed, we’ll use the
// allocator’s construct member to create objects in that space when we need
// to add an element. Similarly, when we remove an element, we’ll use the
// destroy member to destroy the element.
std::allocator<std::string> StrVec::alloc;


// If there isn’t room for another element, chk_n_alloc will call reallocate
// to get more space.
void StrVec::checkAndAllocate() {
    if (size() == capacity())
        reallocate();
}
