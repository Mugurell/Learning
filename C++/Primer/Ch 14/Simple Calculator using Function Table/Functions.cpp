/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          24-Jul-15, 04:20 PM
 *  Last updated:     24 Jul 2015, 21:56:00:447
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
 *  A separate implementation file for Functions is not really needed for now...
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  Used the scope resolution operator " :: " to specify that isdigit() should
 *  be found in the global namespace.
 *  Even if declare " using namespace std " so to not need "std::"
 *  in front of cout for example, would still need to use ::isdigit() !!!
 *
********************************************************************************
*******************************************************************************/


#include <cctype>       // ::isspace()
#include <iterator>     // std::next()

#include "Functions.h"


std::map<std::string, std::function<long double(const int, const int)>>
Functions::math = {
        {"+", Functions::add},     // my function to add integers
        {"-", std::minus<int>()},   // a library function object
        {"/", Divide()},    // my predefined functor
        // inplace constructed unnamed object of unnamed class
        {"*", [] (const int &a, const int &b) { return a * b; }},
        {"%", modulo}      // predefined lambda
};


std::string
Functions::decrypt_gibberish(const std::string &gibberish, int &nr1, int &nr2)
{
    std::string operation;  // will hold the decrypted user choice
    bool no1 = false,       // decrypted the first operand
         no2 = false,       // decrypted the second operand
         op = false;        // decrypted the math operation user wanted

    // The gibberish string will be checked against the following format
    // - 'Q' or 'q'
    // - int - math operator - int
    // - gibberish
    for (std::string::const_iterator curr = gibberish.begin(),
         end = gibberish.end(); curr != end; ++curr)
    {
        // 1) Check if the user wants to quit
        if (*curr == 'Q' || *curr == 'q') {
            operation = "Q";
            break;
        }
        // 2) Try to decrypt a math operation
        if (::isdigit(*curr) && !no1 && !no2) {
            (nr1 *= 10) += *curr - '0';    // convert ascii char to ascii number
            if (!isdigit(*(curr+1)))
                no1 = true;
        }
        else if (::isdigit(*curr) && no1 && !no2) {
            (nr2 *= 10) += *curr - '0';    // convert ascii char to ascii number
            if (((curr+1)) == gibberish.end() || !::isdigit(*(curr+1)))
                no2 = true;
        }
        else if ((*curr == '+' || *curr == '-' || *curr == '/'
                 || *curr == '*' || *curr == '%') && !op && no1 && !no2) {
            operation = *curr;
            op = true;
        }
        else if (::isspace(*curr)) {   // skip any leading whitespaces
            continue;
        }
        // If all of the above failed user probably entered gibberish.
        else
            operation = "gibberish";
    }

    return operation;
}


int Functions::add(const int &a, const int &b)
{
    return a + b;
}