/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 19 iunie 2015, 22:53:52 +0300
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
**  Exercise 11.20: Rewrite the word-counting program from § 11.1 (p. 421)
**  (word_counting_using_map_and_set) to use insert instead of subscripting.
**  Which program do you think is easier to write and read?
**  Explain your reasoning.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None ---  
**
**  Notes:
**  A trebuit sa folosesc auto .... mehhhh... IDK why...
**  Remember that Scott Meyer recommends using emplace instead of insert.
**
**  Regarding the exercise requirements... I guess it it easier to write and
**  unserstand  
**                  while(std::cin >> string);
**                      ++map[string];
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>      // for std::pair


int main()
{
    std::cout << "\nSay what you will, I'll count how many times"
              << "\neach word was typed.\n" << std::endl;

    std::map<std::string, unsigned short int> map;
    std::string buff;
    while (std::cin >> buff) {
//map.insert() will return a pair<position_of_the_inserted_element_in_map, 
//                                bool_to_indicate_if_the_insert_succeded>        
        // std::pair<std::map<std::string, unsigned short int>::iterator, bool>> 
        //         it = map.emplace(buff, 1);
        auto it = map.insert({buff, 1});
// if the bool is false, increment the value assigned to that key
        if (!it.second)
            ++it.first->second;
    }


    // while (std::cin >> buff) {
    //     // inserts an element with key equal to buff and value 1;
    //     // if buff is already in map, insert does nothing
    //     auto ret = map.insert({buff, 1});
    //     if (!ret.second) // buff was already in map
    //     ++ret.first->second; // increment the counter
    // }


    std::cout << "\n\nSo you had:" << std::endl;
    for (std::pair<std::string, unsigned short int> each_word : map)
        std::cout << '\t' << "Word \"" << each_word.first
                  << "\" was repeated " << each_word.second
                  << ((each_word.second > 1) ? " times." : " time.")
                  << std::endl;

    std::cout << "\n\nPretty cool, huh?\n" << std::endl; 
    return 0;
}