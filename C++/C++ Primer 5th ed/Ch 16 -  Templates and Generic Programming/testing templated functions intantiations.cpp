/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          27-Aug-2015, 14:53
 *  Last updated:     
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
 *  Exercise 16.36: What happens in the following calls:
 *  template <typename T> f1(T, T);
 *  template <typename T1, typename T2> f2(T1, T2);
 *  
 *      int i = 0, j = 42, *p1 = &i, *p2 = &j;
 *      const int *cp1 = &i, *cp2 = &j;
 *      (a) f1(p1, p2);
 *      (b) f2(p1, p2);
 *      (c) f1(cp1, cp2);
 *      (d) f2(cp1, cp2);
 *      (e) f1(p1, cp1);
 *      (f) f2(p1, cp1);
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


template <typename T> T f1(T, T);
template <typename T1, typename T2> T1 f2(T1, T2);


int main()
{

    int i = 0, j = 42, *p1 = &i, *p2 = &j;
    const int *cp1 = &i, *cp2 = &j;

    f1(p1, p2);     // void f1<int*>(int*, int*)
    f2(p1, p2);     // void f2<int*, int*>(int*, int*)
    f1(cp1, cp2);   // void f1<int const*>(int const*, int const*)
    f2(cp1, cp2);   // void f2<int const*, int const*>(int const*, int const*)

    //f1(p1, cp1); // no matching function for call to 'f1(int*&, const int*&)'
                   // deduced conflicting types for parameter 'T' 
                   // ('int*' and 'const int*')
                   // no matching function for call to 'f1(int*&, const int*&)

    f2(p1, cp1);    // void f2<int*, int const*>(int*, int const*)

    return 0;
}