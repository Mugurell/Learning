/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10 Aug 2015, 17:28:52:059
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *  Exercise 16.6: How do you think the library Begin and End functions that
 *  take an array argument work? Define your own versions of these functions.
 *  Exercise 16.7: Write a constexpr template that returns the size of a given
 *  array.
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
********************************************************************************
*******************************************************************************/



#include <iostream>
#include <vector>
#include <string>

#include "Begin_End.h"
#include "Size.h"


int main()
{
    const char arr1[] {"Ce mica e vacanta mare!"};
    std::vector<std::string> arr2 {"Si", " ", "ce", " ", "dor", " ", "mi-a",
                                   " ", "fost", " ", "de", " ", "ea", "..!"};
    std::cout << "\nThe first character from our array of " << Size(arr1)
              << " elements is " << *Begin(arr1) << ' ' << *End(arr1)
              << "\n\nAnd the first word from our vector of " << Size(arr2)
              << " strings is " << *Begin(arr2) << ' ' << *End(arr2) << '\n';

    return (0);
}