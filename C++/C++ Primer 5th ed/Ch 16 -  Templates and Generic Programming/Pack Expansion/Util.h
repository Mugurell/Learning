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


#ifndef PACK_EXPANSION_UTIL_H
#define PACK_EXPANSION_UTIL_H


#include <string>


template<typename T>
std::string debug_rep(const T& t);


template<typename... Args>
std::ostream& errorMsg(std::ostream&, const Args&... reps);


template<typename T>
std::ostream& print(std::ostream& os, const T& t);


template<typename T, typename... Args>
std::ostream& print(std::ostream& os, const T& t, const Args&... reps);



#include "Util.tpp"

#endif //PACK_EXPANSION_UTIL_H
