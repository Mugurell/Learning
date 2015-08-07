/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          05 Jul 2015, 16:26
 *  Last updated:     10 Jul 2015, 19:39:22:454
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
 *  2 simple functions to get the name of the input file and the searched word.
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
*******************************************************************************
******************************************************************************/




#ifndef TEXT_QUERY_USING_CLASSES_AND_SHARED_PTR_GETUSERINPUT_H
#define TEXT_QUERY_USING_CLASSES_AND_SHARED_PTR_GETUSERINPUT_H


#include <iostream>
#include <string>
#include <fstream>


std::string getInputFileName();
std::string getSearchedWord();


#endif //TEXT_QUERY_USING_CLASSES_AND_SHARED_PTR_GETUSERINPUT_H
