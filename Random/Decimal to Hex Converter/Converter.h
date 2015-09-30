/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          28-Sep-15, 06:40 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Template class that that can return the binary or hex representation of
 *  an integer either signed or unsigned - using two's complement.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *
********************************************************************************
*******************************************************************************/


#ifndef DECIMAL_TO_HEX_CONVERTER_UTIL_H
#define DECIMAL_TO_HEX_CONVERTER_UTIL_H


#include <climits>
#include <iostream>
#include <map>
#include <string>


template <typename T = long long>
class Converter
{
public:
    Converter(const T& dec);

    // Print the binary/hex representation of decimal to cout.
    std::string         getBinary();
    std::string         getHex();

private:
    const T         decimal;        // number with which the object was init
    bool            is_negative;
    T               binary_bits;
    std::string     binary_representation;
    std::string     hex_representation;

    static std::map<std::string, char>  bin_hex_map;
    static std::string hex_values;

    // This functions will initialize the corresponding private members
    // To be called only by getBinary() and getHex()
    void decimalToBinary();
    void decimalToHex();
};


#include "Converter.tpp"


#endif //DECIMAL_TO_HEX_CONVERTER_UTIL_H
