/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          18 Jul 2015, 09:32:35:959
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
 *  ---
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

#include "StrBlob.h"
#include "StrBlobPtr.h"


int main()
{
    std::cout << "\n\nThis is just a test.\n\n";

    StrBlob a1 = { "hi", "bye", "now" };
    StrBlobPtr p(a1);   // p points to the vector inside a1
    *p = "okay";        // assigns to the first element in a1
    std::cout << p->size() << std::endl; // prints 4, the size of the first 
                                         // element in a1
    std::cout << (*p).size() << std::endl; // equivalent to p->size()

    return 0;
}