/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          23 Sep 2015, 18:06:09:201
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *  " http://forum.softpedia.com/topic/1031828-tema-perechile-de-cuvinte-cu-cel-
 *  putin-doua-secvente-identice-de-x-litere-consecutive/ "
 *  Pe prima linie a fisierului date.in se afla cuvinte despartite prin unul sau
 *  mai multe spatii. Sa se afiseze perechile de cuvinte cu proprietatea ca au
 *  cel putin doua secvente identice de 3 litere consecutive.
 *  Daca nu a fost gasita nici o pereche se va afisa mesajul "fara solutie".
 *  (C++, incepatori clasa a 7-a).
 *
 *  My take on this: read a text file, print all the pairs of words that
 *  have at least 2 pairs of identical 3 letter substrings.
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
#include <map>
#include <string>
#include <vector>

#include "Util.h"


int main()
{
    std::cout << "Please enter the name/full path to a file to be used as "
            "input:\n\t";
    std::string inputFileName;
    std::cin >> inputFileName;

    std::vector<std::string> textRead = Util::ReadTextFromFile(inputFileName);

    std::map<std::string, std::vector<std::string>>
            slidingWindows = Util::FormSlidingWindows(textRead);

    Util::PrintFoundDuplicates(slidingWindows);
}
