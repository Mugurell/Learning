/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          22-Jul-15, 09:43 PM
 *  Last updated:     22 Jul 2015, 22:54:49:153
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
 *  Implementation file for test SizeTest class.
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


#include "SizeTest.h"


SizeTest::SizeTest(size_t min, size_t max)
    : min_size(min), max_size(max) { }

bool SizeTest::operator()(std::string word)
{
    std::string::size_type word_size = word.size();
    return word_size >= min_size && word_size <= max_size;
}