/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10 Aug 2015, 15:08:14:118
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *  Exercise 16.5: Write a template version of the print function from § 6.2.4
 *  (p. 217) that takes a reference to an array and can handle arrays of any
 *  size and any element type.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  Came up with 2 interesting templated print functions for an array
 *
********************************************************************************
*******************************************************************************/



#include <iostream>
#include <array>
#include <string>

#include "Print.h"


int main()
{

    char hey[] = "\nHey";   // compiler will insert a null terminator at the end
    std::string guys[] {"guys", " how's", " it", " going?"};
    int numbers[] {1, 3, 5, 7, 9};
    std::array<int, 3> extra {1, 2, 3};
    Print2(hey);
    Print(guys);

    std::cout << "\n\nToday's lucky number is.. : ";
    Print2(numbers);
    Print2(extra);    // don't work with Print()

    return 0;
}