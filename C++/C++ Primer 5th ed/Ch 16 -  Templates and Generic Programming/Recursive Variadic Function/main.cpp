/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          25 Sep 2015, 18:00:11:233
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *   Exercise 16.53: Write your own version of the print functions and test
 *  them by printing one, two, and five arguments, each of which should have
 *  different types.
 *   Exercise 16.54: What happens if we call print on a type that doesn’t have
 *  an << operator?
 *   Exercise 16.55: Explain how the variadic version of print would execute if
 *  we declared the nonvariadic version of print after the definition of the
 *  variadic version.
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


// C++ Primer: If this wasn't declared at all, or if this wasn't declared
// before the variadic version, that variadic print function will be
// recursively called indefinitely.
// My test: In both cases: Compilation error: the variadic template function
// expects at least 2 arguments, 1 provided.
template<typename T>
std::ostream& print(std::ostream &os, const T &t)
{
    return os << "\nNon-variadic function says: " << t;
}

template<typename T, typename... Args>
std::ostream& print(std::ostream &os, const T &t, const Args&... rest)
{
    os << "\nVariadic function says: " << t;

    // This will call the variadic template function recursively until
    // sizeof...(rest) == 1, case in which the normal non-variadic function
    // will be called because it is more specialized than this variadic function
    // which also takes an std::ostream& and a T but 0 other objects.
    return print(os, rest... );
}

class Simple{ };


int main()
{
    const char *hey = "\n\tbye\n";
    char ch = 'a';

    print(std::cout, std::string{"Say no to drugs!\n"});

    print(std::cout, std::string{"Hey"}, ch, 17, 3.14, hey );

    // Compilation errors: Starting from "error: no match for 'operator<<'"
    // the compiler would try to implicitly convert the Simple object to an
    // available object for which the 'operator<<' is defined, like int, bool,
    // cont char*, std::error_code, etc.
//    Simple simple;
//    print(std::cout, simple);

    return 0;
}