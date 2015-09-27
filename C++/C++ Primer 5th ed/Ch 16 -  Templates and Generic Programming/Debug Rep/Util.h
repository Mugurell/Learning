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


#ifndef DEBUG_REP_UTIL_H
#define DEBUG_REP_UTIL_H


#include <sstream>


namespace Util
{

/*
 * A normal, non-template function with the same name as the others.
 * A non-template function will always be preferred when same arguments.
 */
// std::string debug_rep(const std::string& s);





/*
 * Can be used to generate a string
 * corresponding to an object of any type that has an output operator
 */
//template<typename T>
//std::string debug_rep(const T &t);




/*
 * Print pointers as their pointer value,
 * followed by the object to which the pointer points.
 * NB: this function will not work properly with char*.
 */
template<typename T>
std::string debug_rep(T *p);


#include "Util.tpp"

}


#endif //DEBUG_REP_UTIL_H

