/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          21-Jul-15, 10:13 PM
 *  Last updated:     22 Jul 2015, 17:05:24:903 
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
 *  A simple Function-Object class that can be used in stl algorithms to
 *  replace duplicates of ints or strings from vector<int> / vector<string>.
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


#ifndef ALGORITHMS_AND_FUNCTORS_REPLACEDUPES_H
#define ALGORITHMS_AND_FUNCTORS_REPLACEDUPES_H


#include <string>


class ReplaceDupes {
public:
    ReplaceDupes(int nr1 = 44, int nr2 = 33);
    ReplaceDupes(std::string w1 = "Johanna", std::string w2 = "Katerina");

    int operator() (int nr);
    std::string operator() (std::string w);

private:
    int dupeNr;
    int newNr;
    std::string dupeWord;
    std::string newWord;
};



#endif //ALGORITHMS_AND_FUNCTORS_REPLACEDUPES_H
