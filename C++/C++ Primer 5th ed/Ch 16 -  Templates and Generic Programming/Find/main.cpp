/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10 Aug 2015, 13:20:59:696
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *  Exercise 16.4: Write a template that acts like the library find algorithm.
 *  The function will need two template type parameters, one to represent the
 *  function’s iterator parameters and the other for the type of the value. Use
 *  your function to find a given value in a vector<int> and in a
 *  list<string>.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  Didn't respected the exercise fully, but it works the same way.
 *
********************************************************************************
*******************************************************************************/



#include <iostream>
#include <vector>
#include <string>
#include <list>

#include "Find.h"


int main()
{
    std::cout << "\nLet's say we have a nice little vector of strings,"
              << "\n... some might call it a poem..."
              << "\n... others inpirationanl"
              << "\nand others just mondane crap:\n";

    std::vector<std::string> poem {"\n", "Watch", "your", "thoughts",
                                   "\n", "They", "become", "words",
                                   "\n", "Watch", "your", "words",
                                   "\n", "They", "become", "deeds",
                                   "\n", "Watch", "your", "deeds",
                                   "\n", "They", "become", "habits",
                                   "\n", "Watch", "your", "habits",
                                   "\n", "They", "become", "character",
                                   "\n", "Character", "is", "everything"};
    for (const std::string &each_word : poem)
        std::cout << each_word << ' ';

    std::cout << "\n\nFrom all of that what word does inspire you the most?"
              << "\n\t-> ";
    std::string searched_word;
    std::cin >> searched_word;
    std::cin.ignore(100, '\n');
    if (Find(poem.begin(), poem.end(), searched_word) != poem.end())
        std::cout << "\nKnow what you mean.. Profound stuff!\n";
    else
        std::cout << "\nHmmmm :-|\n";

    // initialize a list of chars to be the base of our search
    std::list<char> base_word(searched_word.begin(), searched_word.end());
    std::cout << "\nAnd from that word, what letter in particular?\n\t-> ";
    char searched_letter;
    std::cin >> searched_letter;
    if (Find(base_word.cbegin(), base_word.cend(), searched_letter)
        != base_word.end())
        std::cout << "\nRight!? Totally agree with you!\n";
    else
        std::cout << "\nHmmmm :-|\n";

    return 0;

}