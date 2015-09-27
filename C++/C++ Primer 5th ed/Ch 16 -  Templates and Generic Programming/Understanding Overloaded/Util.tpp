/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          24-Sep-15, 09:43 PM
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


#include <iostream>
using namespace std;

#include "Util.h"


template <typename T> void f(T)
{
    cout << "\nvoid f(T)" << endl;
}


template <typename T> void f(const T*)
{
    cout << "\nvoid f(const T*)" << endl;
}


template <typename T> void g(T)
{
    cout << "\nvoid g(T)" << endl;
}


template <typename T> void g(T*)
{
    cout << "\nvoid g(T*)" << endl;
}