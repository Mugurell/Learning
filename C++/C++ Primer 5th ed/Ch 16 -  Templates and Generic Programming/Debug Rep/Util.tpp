/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          24-Sep-15, 06:41 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Implementation file for the template functions declared in Util.h
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


template<typename T>
std::string debug_rep(const T &t)
{
    std::ostringstream ret;
    ret << t;   // use T's output operator to print a representation of t
    return ret.str();  // return a copy of the string to which ret is bound
}


template<typename T>
std::string debug_rep(T *p)
{
    std::ostringstream ret;
    // print the memory address of p's pointee
    ret << "\npointer " << p << " - ";
    // print the value at that address or a message signaling nullptr
    ret << (p == nullptr ? "null pointer" : debug_rep(*p));
    return ret.str();
}


//std::string debug_rep(const std::string& s)
//{
//    return '"' + s + '"';   // the received string, enclosed in quotes
//}