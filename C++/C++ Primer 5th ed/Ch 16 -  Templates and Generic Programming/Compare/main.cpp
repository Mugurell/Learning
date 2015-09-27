/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          09 Aug 2015, 22:11:13:799
 *  Last updated:     10 Aug 2015, 13:14:29:160
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Exercise 16.2: Write and test your own versions of the compare functions.
 *  Exercise 16.3: Call your compare function on two Sales_data objects to
 *  see how your compiler handles errors during instantiation.
 *  " error: no match for 'operator<'
 *  (operand types are 'const Sales_data' and 'const Sales_data') "
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  Used some overloaded operators of Sales_data.
 *  Not necessarily needed but fun!
 *
********************************************************************************
*******************************************************************************/



#include <iostream>
#include <string>

#include "Compare.h"
#include "Sales_data.h"

void printResult(const int result);

int main()
{
    std::cout << "\nIf we're to compare 21 and 432, "
              << "\nwe'd get that ";

    printResult(compare(21, 432));

    Sales_data book1("Harry Potter", 2, 50);
    Sales_data book2("Margelatu'", 3, 60);
    std::cout << "\n\nBut if we're to compare two Sales_data,"
              << "\nlet's say \"" << static_cast<std::string>(book1) << '\"'
              << " (" << book1 << ')'
              << "\nand \"" << static_cast<std::string>(book2) << '\"'
              << " (" << book2 << ')'
              << "\nwe'd get that ";

    printResult(compare(book1, book2));

    std::cout << "\n\nPretty cool, huh?\n\n";
    return 0;
}


void printResult(const int result)
{
    switch (result) {
        case -1:
            std::cout << "first element is less than the second.\n";
            break;
        case  1:
            std::cout << "first element is greater than the second.\n";
            break;
        case  0:
            std::cout << "both elements are actually equal.\n";
            break;
        default:
            std::cout << "shouldn't be doing this!\n";
            break;
    }
}