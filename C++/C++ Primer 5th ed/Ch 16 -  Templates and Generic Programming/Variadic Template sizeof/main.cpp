/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          25 Sep 2015, 16:42:45:303
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *   Exercise 16.51: Determine what sizeof...(Args) and sizeof...(rest) return
 *  for each call to foo in this section.
 *   Exercise 16.52: Write a program to check your answer to the previous
 *  question.
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
#include <string>


template<typename T, typename... Args>
void foo(const T& , const Args&... rest)
{
    std::cout << "\n\nsizeof...(Args) - " << sizeof...(Args);
    std::cout << "\nsizeof...(rest) - " << sizeof...(rest);
}


int main()
{
    int i = 0;
    double d = 3.14;
    std::string s = "how now brown cow";

    foo(i, s, 42, d); // three parameters in the pack
    foo(s, 42, "hi"); // two parameters in the pack
    foo(d, s);        // one parameter in the pack
    foo("hi");        // empty pack

    return 0;
}