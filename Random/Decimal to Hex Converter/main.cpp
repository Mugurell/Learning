/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          28 Sep 2015, 18:31:00:462
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *  A simple program that uses the Converter template class to get the binary
 *  and hex representation of a given integer.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  F U N
 *
********************************************************************************
*******************************************************************************/


#include <iostream>
#include <climits>

#include "Converter.h"


int main()
{
    std::cout << "\nWelcome to the great Decimal to Hex Converter!!\n\n";
    std::cout << "\nYou can enter any decimal value in the range\n\t["
        << LLONG_MIN << " - " << LLONG_MAX << "]\n";
    std::cout << "(If you want to quit the program, just type any symbol other)"
        "than a numeric one.)";
    std::cout << "\n\nThat being said..\n";

    while (1)
    {
        std::cout << "\nEnter the decimal value to be converted:\n\t->";
        long long decimal;
        std::cin >> decimal;
        Converter<> converter(decimal);

        if (std::cin.good())   // check for any error flags
        {
            std::cout << '\n' << decimal << " in hex is ";

            if (decimal >= 0 && decimal <= 9)
                std::cout << "still... 0x" << decimal;
            else
                std::cout << converter.getHex();

            std::cout << "\nAnd it's binary representation is "
                << converter.getBinary();
        }
        else {
            std::cout << "\n\nOk, cool\n\n\tBye!";
            break;
        }

        std::cout << "\n\n";
        std::cin.ignore(100, '\n');
    }

    return 0;

}
