/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          24 Sep 2015, 18:46:28:061
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *  Exercise 16.48: Write your own versions of the debug_rep functions.
 *  So here I'm testing overloaded template functions.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  In mod normal, daca vrei sa folosesti o functie, dar pe care ai uitat sa
 * o declari inainte sa o definesti, nu o sa compileze.
 *  Dar daca ai o functie templatizata care nu a fost declarata mai inainte,
 * dar totusi a fost definita, in cazul in care ea este cea mai potrivita
 * functie pt. a fi chemata, programul va fi compilat si aceasta va fi folosita
 * doar pe baza definitiei!
 *
 *  => Desi functia templatizata care ia un const T& nu a fost declarata (e
 *  comentata in Util.h, programul compileaza si aceasta este folosita doar
 *  pe baza definitiei din Util.tpp
 *
********************************************************************************
*******************************************************************************/



#include <iostream>
#include <string>
#include "Util.h"


int main()
{
    std::string ana{"Ana"};
    std::cout << Util::debug_rep(ana);   // call the one that takes a const T&
    std::cout << Util::debug_rep(&ana);  // call the one that takes a T*
    std::string *ptr = &ana;
    std::cout << Util::debug_rep(ptr);  // call the one that takes a T*

    return 0;
}