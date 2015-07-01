/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 18 iunie 2015, 22:30:08 +0300
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
**  Exercise 11.12: Write a program to read a sequence of strings and ints,
**  storing each into a pair. Store the pairs in a vector.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  uint8_t e absent... ziceam sa-l folosesc pt count.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <utility>      // for pair
#include <cstdint>      // for uint8_t


int main()
{
    std::cout << "\nPlease enter sequences of words and ints:\n" << std::endl;

    std::vector<std::pair<std::string, int>> vector;
    std::pair<std::string, int> pair;
    std::string word, quit("quit");
    int nr;
    while (1) {
        std::cin >> word;
        if (word == quit)
            break;
        std::cin >> nr;
        vector.push_back(std::make_pair(word, nr));
    }

    std::cout << "\n\nSo we had:" << std::endl;
    unsigned short count = 1;
    for (const auto &each_pair : vector) {
        std::cout << '\t' << count++ << ": " << each_pair.first << ' ' 
                  << each_pair.second << std::endl;
    }

    std::cout << "\n\nPretty cool, huh?\n" << std::endl;
    return 0;
}
