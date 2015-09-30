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
 *  Implementation file for the Converter template class.
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
#include <climits>


template <typename T>
Converter<T>::Converter(const T& dec) : decimal{dec}
{
    if (dec < 0)
        is_negative = true;
    else
        is_negative = false;

    binary_bits = 0;

    // initialize binary_bits and binary_representation
    decimalToBinary();
    // initialize hex representation;
    decimalToHex();
}


template <typename T>
std::map<std::string, char>
Converter<T>::bin_hex_map { {"0000", '0'}, { "0001", '1'}, {"0010", '2'},
                         {"0011", '3'}, {"0100", '4'}, {"0101", '5'},
                         {"0110", '6'}, {"0111", '7'}, {"1000", '8'},
                         {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'},
                         {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'},
                         {"1111", 'F'}
                       };

template <typename T>
std::string
Converter<T>::hex_values {"0123456789ABCDEF"};


template <typename T>
std::string Converter<T>::getBinary()
{
    return binary_representation;
}

template <typename T>
std::string Converter<T>::getHex()
{
    return hex_representation;
}

template <typename T>
void Converter<T>::decimalToBinary()
{
    T number = decimal;     // buffer for the const decimal
    short count = 0;


    if (number == 0)
    {
        binary_representation = "0000";
        return;
    }


    /*
     * We can have 2 cases:
     *   - the decimal entered by the user is a positive number, all good
     *   - the decimal entered by the user is a negative number, in which case,
     *   to get the binary representation of a negative number we can:
     *      - express the absolute value in binary
     *      - use two's complement to convert all 1's to 0's and all 0's to 1's
     *      - add 1
     */
    if (number < 0)
    {
        // get the absolute value
        number = llabs(number);
    }


    // Store the bit values of the abs(decimal) in a long long integer
    // Of course, after this loop binary_bits == decimal. But when decimal is
    // negative, binary_bits holds the overflow and also and we also have the
    // number of bits needed to express the positive decimal.
    while (number > 0)
    {
        // when dividing by 2 the remainder is the bit value
        binary_bits |= number % 2 << count++;
        number >>= 1;
    }


    // store the bit values in an easier to work with container, a string
    if (is_negative)
    {
        binary_bits = ~binary_bits + 1;
        std::cout << "\n\n";
        for (int x = 31; x >= 0; x--)
        {
            if (binary_bits & 1 << x) {
                binary_representation.push_back('1');
            }
            else {
                binary_representation.push_back('0');
            }
        }
    }
    else {
        //short position{0};
        while (count-- > 0)
        {
            char current_bit_value = (binary_bits & 1 << count ? 1 : 0);
            binary_representation.push_back(current_bit_value + 48);
        }
    }

}


// There are 2 ways to calculate a hex number: either from the decimal,
// either from the binary. Will be using both.
template <typename T>
void Converter<T>::decimalToHex()
{
    if (is_negative)
    {
        // Read the binary representation string, in 4 character groups -
        // corresponding to each hex symbol
        for (std::string::const_iterator it= binary_representation.cbegin();
            it != binary_representation.cend(); it += 4)
        {
            // add each hex representation for each 4 bits values
            hex_representation.push_back(bin_hex_map.at
                                               (std::string(it, it + 4)));
        }
    }

    else
    {
        T number = binary_bits;
        // Using easiest way of converting directly from positive decimal to hex
        while (number > 0)
        {
            // Hex code is formed from the remainders of the number/16 division
            hex_representation.insert(hex_representation.begin(),
                                      hex_values.at(number % 16));
            number /= 16;
        }
        hex_representation.insert(hex_representation.begin(), {'0', 'x'});
    }
}
