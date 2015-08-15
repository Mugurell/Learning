/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          11 Aug 2015, 13:25:05:602
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Exercise 16.12: Write your own version of the Blob and BlobPtr templates
 *  including the various const members that were not shown in the text.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  Like StrBlob, our template will provide shared (and checked) access to the
 *  elements it holds. Unlike that class, our template can be used on elements
 *  of pretty much any type. As with the library containers, users will have
 *  to specify the element type when they use a Blob.
 *
********************************************************************************
*******************************************************************************/



#include <iostream>

#include "Blob.h"

int main()
{
    Blob<int> numbers {2, 4, 6, 8};

    std::cout << "\nThe " << numbers.size() << "th element from our vector"
              << " is " << numbers.back() << ".\n\n";
    return 0;
}