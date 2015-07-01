/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 18 iunie 2015, 21:05:10 +0300
**  Last updated:           ---
**
**  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**                    -Wmissing-format-attribute -Wmissing-include-dirs  
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
**
**  Execution:    ./...
**
**  Description:
**  Exercise 11.9: Define a map that associates words with a list of line
**  numbers on which the word might occur.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  Why not use a map in which the key whould represent the line and the value
**  would be the words on that line (key)?
**  Could've used a map<std::size_t, std::string> but in this way I have 
**  power over every word in a read line.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <map>


int main()
{
    std::cout << "\nWrite whatever you like, preferrable on multiple lines"
              << "\nand I'll store the info about which words were on which "
              << "lines.\nGo!\n" << std::endl;

// Exercise requirement:
    std::map<std::string, std::list<std::size_t>> m;



// My exercise
    std::map<std::size_t, std::vector<std::string>> map;
    //std::map<std::size_t, std::string> map;
    std::size_t line_nr = 0;

    std::string word;
    while (std::getline(std::cin, word)) {
        line_nr++;
        // map[line_nr] = word       // if I'd use a map with string values
        std::istringstream line(word);
        while (line >> word)
            map[line_nr].push_back(word);
    }


    std::cout << "\n\nCool!\n"
              << "So you've said the following:";

    for (const auto each_line : map) {
        std::cout << "\n\tLine " << each_line.first << ": ";
        for (auto each_word : each_line.second)
            std::cout << each_word << ' ';
    }

    std::cout << "\n\nPretty cool, huh?\n" << std::endl;
    return 0;
}