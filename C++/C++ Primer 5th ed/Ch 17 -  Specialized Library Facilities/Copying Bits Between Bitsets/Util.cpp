/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          08-Oct-15, 11:52 AM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
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
********************************************************************************
*******************************************************************************/


#include <iostream>
#include "Util.h"

using namespace Util;


void Util::initializeBitset(std::bitset<64>& bitset,
                            const std::initializer_list<int> bits)
{
    // tabula rasa
    bitset.reset();
    for (const int each : bits) {
        bitset[each] = true;
    }
}


void Util::copyBitset(const std::bitset<64> &source,
                      std::bitset<64> &dest)
{
    if (source.any())   // if any bit is on in source
    {
        // One method would involve saving all bits in a string then
        // initialize the new bitset from this string
        // Will use a method involving only bitset functions though..
        int count = source.size();     // number of bits in source
        while (--count >= 0)
        {
            dest.set(count, source[count]);
        }

    }
    else
        dest.reset();
}


void Util::printOnBits(const std::bitset<64> &bitset)
{
    if (bitset.any())
    {
        int count = bitset.size();
        while (--count >= 0)
        {
            if (bitset.test(count) == true)
                std::cout << count << ' ';
        }
    }
    else
        std::cout << "\nNo bits are on!";
}