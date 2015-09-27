/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          24 Sep 2015, 21:40:11:391
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *  Exercise 16.49: Explain what happens in each of the following calls:
 *      template <typename T> void f(T);
 *      template <typename T> void f(const T*);
 *      template <typename T> void g(T);
 *      template <typename T> void g(T*);
 *          int i = 42, *p = &i;
 *          const int ci = 0, *p2 = &ci;
 *      g(42); g(p); g(ci); g(p2);
 *      f(42); f(p); f(ci); f(p2);
 *  Exercise 16.50: Define the functions from the previous exercise so that they
 * print an identifying message. Run the code from that exercise. If the calls
 * behave differently from what you expected, make sure you understand why.
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

#include "Util.h"



int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    /*
     * template <typename T> void f(T);
     * template <typename T> void f(const T*);
     * template <typename T> void g(T);
     * template <typename T> void g(T*);
     */

    g(42);  // void g(T)  - T is int, perfect match
    g(p);   // void g(T*) - T is int*, perfect match

    // There's no way to instantiate a function template that expects a pointer
    // type from a nonpointer argument
    g(ci);  // void g(T)  - T is const int, only 1 viable template function
    g(p2);  // void g(T*) - T is const int*,

    f(42);  // void f(T) - perfect match
    f(p);   // void f(T) - T is deduced as int*, better match
    f(ci);  // void f(T) - T deduced as const int, only 1 viable template fc
    f(p2);  // void f(const T*) - perfect match
}