/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          09 Jul 2015, 20:19:39:683
 *  Last updated:     10 Jul 2015, 17:53:15:382
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
 *  Some classes need to allocate a varying amount of storage at run time.
 *  Such classes often can (and if they can, generally should) use a library
 *  container to hold their data.
 *  For example, our StrBlob class uses a vector to manage the underlying
 *  storage for its elements.
 *  However, this strategy does not work for every class; some classes need to
 *  do their own allocation. Such classes generally must define their own
 *  copy-control members to manage the memory they allocate.
 *  As an example, we�ll implement a simplification of the library vector class.
 *  Among the simplifications we�ll make is that our class will not be a
 *  template. Instead, our class will hold strings. Thus, we�ll call our
 *  class StrVec.
 *
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


int main()
{
    std::cout << "\n\nThis is just a test!\n\n";

    StrVec vec{"Ana"};
    std::cout << "vec.capacity() = " << vec.capacity() << "\n\n";
    vec.push_back("Aneta");
    vec.push_back("Aniela");
    vec.reserve(20);
    std::cout << "After vec.reserve(20) - " << vec.capacity() << "\n\n";
    vec.resize(10);
    std::cout << "After vec.resize(10) - " << vec.capacity() << "\n\n";
    return 0;
}

