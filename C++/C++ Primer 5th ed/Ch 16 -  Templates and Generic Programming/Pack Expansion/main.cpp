/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          25 Sep 2015, 22:11:03:354
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Exercise 16.56: Write and test a variadic version of errorMsg.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *   How this works:
 *  - errorMsg calls debug_rep on every element
 *  - debug_rep returns a std::string representation of each object
 *  - then, errorMsg calls a template function - print, overloaded on variadic
 *  template pack or not, which prints that string representation that debug_rep
 *  outputted to a std::ostream.
 *
********************************************************************************
*******************************************************************************/



#include <iostream>
#include <string>

#include "Util.h"


int main()
{
    errorMsg(std::cout, std::string{"Hey"}, 24, 3.15 );

    return 0;
}