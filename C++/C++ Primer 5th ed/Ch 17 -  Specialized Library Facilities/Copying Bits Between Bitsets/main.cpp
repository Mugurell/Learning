/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          08 Oct 2015, 11:51:11:969
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *   Exercise 17.10: Using the sequence 1, 2, 3, 5, 8, 13, 21, initialize a
 *  bitset that has a 1 bit in each position corresponding to a number in this
 *  sequence. Default initialize another bitset and write a small program to
 *  turn on each of the appropriate bits.
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



#include <bitset>
#include <iostream>

#include "Util.h"


int main()
{
    std::cout << "\nLet's say we have a std::bitset<21> with bits turned on "
        "\nat positions ";
    std::bitset<64> bitset;
    Util::initializeBitset(bitset, {1,2,3,5,8,13,21});
    Util::printOnBits(bitset);


    std::cout << "\n\nNow, let's initialize a new bitset with the same exact "
        "values.\nAnd let's test to see which bits are on in the new bitset.."
        << "\nSo we have bits turned on at positions\n\t";
    std::bitset<64> another;
    // basically copy one binary to another
    Util::copyBitset(bitset, another);
    Util::printOnBits(another);

    std::cout << "\n\nPretty cool, huh?\n";
}
