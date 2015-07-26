/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          24-Jul-15, 04:20 PM
 *  Last updated:     24 Jul 2015, 21:56:06:029
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
 *  We'll use a functions table to hold various types of callable objects used
 *  to do the main mathematical operations of a calculator.
 *  For this we’ll use a string corresponding to an operator symbol as the key;
 *  The value will be the function that implements that operator.
 *  When we want to evaluate a given operator, we’ll index the map with that
 *  operator and call the resulting element.
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


#ifndef SIMPLE_CALCULATOR_USING_FUNCTION_TABLE_FUNCTIONS_H
#define SIMPLE_CALCULATOR_USING_FUNCTION_TABLE_FUNCTIONS_H


#include <map>
#include <functional>       // for std::function<>
#include <string>


// predefine a functor to be used in our functions table
struct Divide {
    double operator() (const double &denominator, const double &divisor) {
        double result = denominator / divisor;
        return result;
       // return denominator / divisor;
    }
};

// named lambda to be used in out functions table
    auto modulo = [] (const int &a, const int &b) -> int {
        return a % b;
    };



struct Functions {
    // small function to be used in our functions table
    static int add(const int &a, const int &b);

    // create a function table initialized with all 5 types of callable objects
    static std::map<std::string,
                    std::function<long double(const int, const int)>> math;


    // function to understand user input
    // - perform a basic math operation, or
    // - quit the program
    static std::string decrypt_gibberish(const std::string &gibberish,
                                        int &nr1, int &nr2);
};



#endif //SIMPLE_CALCULATOR_USING_FUNCTION_TABLE_FUNCTIONS_H
