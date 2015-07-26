/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          15 Jul 2015, 21:37:34:037
 *  Last updated:     26 Jul 2015, 16:36:27:591
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

#include "Sales_data.h"



int main()
{
    std::cout << "\nThis is just a test\n"
              << "\nPlease enter the isbn, number of units sold and price"
              << "\nfor book 1 : ";
    Sales_data book1, book2;
    std::cin >> book1;
    std::cout << "\nNow do the same again\nfor book 2 : ";
    std::cin >> book2;

    std::cout << '\n' << book1 << '\n' << book2 << '\n' << std::endl;

    // static_cast needed because our conversion operators are explicit
    std::cout << "\n\tSo book1 did:  " << static_cast<double>(book1)
              << "\n\tand book2 did: " << static_cast<double>(book2)
              << "\n\nNice!\n\n";


    return 0;
}
