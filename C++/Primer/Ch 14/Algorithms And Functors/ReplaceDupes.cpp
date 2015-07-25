/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          21-Jul-15, 10:13 PM
 *  Last updated:     22 Jul 2015, 17:05:15:805 
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
 *  Implementation file for the ReplaceDupes class.
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


#include "ReplaceDupes.h"



ReplaceDupes::ReplaceDupes(std::string w1, std::string w2)
    : dupeWord(w1), newWord(w2) { }

ReplaceDupes::ReplaceDupes(int nr1, int nr2)
    : dupeNr(nr1), newNr(nr2) { }


int ReplaceDupes::operator()(int nr)
{
    if (nr == dupeNr)
        nr = newNr;

    return nr;
}

std::string ReplaceDupes::operator()(std::string word)
{
    if (word == dupeWord)
        word = newWord;

    return word;
}