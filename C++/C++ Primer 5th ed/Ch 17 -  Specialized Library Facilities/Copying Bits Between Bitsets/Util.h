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


#ifndef USING_BITSETS_UTIL_H
#define USING_BITSETS_UTIL_H


#include <bitset>
#include <initializer_list>


namespace Util {

    void initializeBitset(std::bitset<64>& bitset,
                          const std::initializer_list<int> bits);
    void copyBitset(const std::bitset<64>& source , std::bitset<64>& dest);

    void printOnBits(const std::bitset<64>& bitset);

}



#endif //USING_BITSETS_UTIL_H
