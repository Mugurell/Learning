/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 26 iunie 2015, 19:16:40 +0300
**  Last updated:           ---
**
**  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**                    -Wmissing-format-attribute -Wmissing-include-dirs  
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
**
**  Execution:    ./...
**
**  Description:
**  Exercise 12.16: Compilers don’t always give easy-to-understand error
**  messages if we attempt to copy or assign a unique_ptr. Write a program
**  that contains these errors to see how your compiler diagnoses them.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None ---  
**
**  Notes:
**  Unlike shared_ptr only one unique_ptr can, at any give time, point to a
**  given object.
**  So the best way to designate another pointer to point to a specific object,
**  allready refered by another unique_ptr is:
**      p2(p1.release) / p2.reset(p1.release)
**  Also, remember that you can return a unique_pointer to an object
**  dinamically alocated inside a function, from that function. C++11 baby! 
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <memory>



int main()
{
// First get a unique_ptr.
    std::unique_ptr<int> p1(new int(42));

    std::cout << "\n\nSo we have a unique_ptr that points to " << *p1
              << std::endl;

// Try the assignment.
// The compiler will give us: "error: use of deleted function"
    // std::unique_ptr<int> p2 = p1;

// Try to copy a unique_ptr to another.
// The compiler will give the same error: "error: use of deleted function"
    //std::unique_ptr<int> p3(p1);

    std::cout << "\n\nPretty col, huh?\n" << std::endl; 
} 