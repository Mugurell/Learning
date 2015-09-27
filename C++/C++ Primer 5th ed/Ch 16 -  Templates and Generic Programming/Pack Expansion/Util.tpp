/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          25-Sep-15, 09:37 PM
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


#include "Util.h"
#include <sstream>


template<typename T>
std::string debug_rep(const T& t)
{
    std::ostringstream output;
    output << '\n' << t;  // use T's output oper. to print a representation of t
    return output.str();  // return copy of the string to which output is bound
}


template<typename... Args>
std::ostream& errorMsg(std::ostream &os, const Args&... reps)
{
    // call debug_rep on each argument in reps
    return print(os, debug_rep(reps)...);
}


template<typename T>
std::ostream& print(std::ostream& os, const T& t)
{
    return os << "\n\nNon-variadic template function: " << t;
}


template<typename T, typename... Args>
std::ostream& print(std::ostream& os, const T& t, const Args&... reps)
{
    os << "\nVariadic function says: " << t;

    return print(os, reps...);
}