/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          27 Sep 2015, 16:44:20:720
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *   Exercise 16.63: Define a function template to count the number of
 *  occurrences of a given value in a vector. Test your program by passing it a
 *  vector of doubles, a vector of ints, and a vector of strings.
 *   Exercise 16.64: Write a specialized version of the template from the
 *  previous exercise to handle vector<const char*> and a program that
 *  uses this specialization.
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

#include "Util.h"



int main()
{
    std::vector<int>          vInt    {1,2,3,4,5,6,7,7,8,9};
    std::vector<double>       vDouble {2.0, 2.3, 2.0, 2.6};
    std::vector<std::string>  vString {"Ana", "are", "mere"};
    std::vector<const char *> vChar   {"Viorel", "vine", "si", "cere"};

    std::cout << '\n' << 7 <<  " is repedeated in our vector "
        << count(vInt, 7) << " times.\n";

    std::cout << '\n' << 2.3 <<  " is repedeated in our vector "
        << count(vDouble, 2.3) << " times.\n";

    std::cout << '\n' << "Ana" <<  " is repedeated in our vector "
        << count(vString, std::string{"Ana"}) << " times.\n";

    std::cout << '\n' << "Viorel" <<  " is repedeated in our vector "
        << count(vChar, const_cast<const char*>("Viorel")) << " times.\n";

    // Now a special test to see when the general template function is called
    std::vector<short> vShort{1,2,3,4,5,6,7,8,9};
    std::cout << '\n' << 2 << " is repeated in out short vector "
        << count(vShort, static_cast<short>(2)) << " times.\n";


    return 0;
}
