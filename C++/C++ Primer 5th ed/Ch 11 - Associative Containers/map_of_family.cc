/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 17 iunie 2015, 22:49:37 +0300
**  Last updated:     sâmbt 20 iunie 2015, 14:28:33 +0300
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
**  Exercise 11.7: Define a map for which the key is the family’s last name and
**  the value is a vector of the children’s names. Write code to add new
**  families and to add new children to an existing family.
**  
**  Exercise 11.14: Extend the map of children to their family name that you
**  wrote for the exercises in § 11.2.1 (p. 424) by having the vector store a
**  pair that holds a child’s name and birthday.
**  
**  Exercise 11.23: Rewrite the map that stored vectors of children’s names
**  with a key that is the family last name to use a multimap.
**
**  Bugs:
**  If the user would not enter a valid age (int) after the kid name, 
**  the program will bork.
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  ---
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>      // for pair


void clear_cin(void);

int main()
{
    std::cout << "\nSo here you can save the names of some families kids.."
              << "\nNot very helpful, but hey... it's nice practice for me :-)"
              << "\n\nFor this we'll use a map,"
              << "\n\tthe key will be the family’s last name,"
              << "\n\tthe value will be a vector of kids names."
              << "\n\nUse Ctrl+D to stop the loop."
              << "\nPress Enter when you're ready" << std::endl;

    std::multimap<std::string, std::vector<std::pair<std::string,short unsigned>> > 
            family;
    std::pair<std::string, short unsigned> kid;
    std::string last_name;
    std::vector<std::string> kids;
    bool new_family = true;

    while (new_family) {
        char response;
        std::cout << "\n\nAdd a new family? [Y] / [N]: ";
        std::cin >> response;
        response >= 'a' && response <= 'z' ? response -= 'a' - 'A' 
                                            : false ;
        switch (response) {
            case 'Y':
                std::cout << "\nEnter family’s last name: ";
                std::cin >> last_name;
                std::cout << "\nAdd a new kid? [Y] / [N]: ";
                std::cin >> response;
                response >= 'a' && response <= 'z' ? response -= 'a' - 'A' 
                                                    : true ;
                switch (response) {
                    case 'Y':
                        std::cout << "\nEnter kids name, followed by age: "
                                  << "(type 'quit' to finish)\n\t";
                        while (std::cin >> kid.first && (kid.first != "quit")){
                            if (std::cin >> kid.second)
                            clear_cin();
                            // family[last_name].push_back(kid);
                            // using below for multimap:
                            std::vector<decltype(kid)> kidvec = {kid};
                            family.insert({last_name, kidvec});
                            std::cout << '\t';
                        }
                        break;
                    case 'N':
                    default: {
                        // family[last_name].push_back
                        //                 (std::make_pair("no kids", 0));
                        // using below for multimap:
                        std::vector<decltype(kid)> 
                            kidvec {std::make_pair("no kids", 0)};
                        family.insert({last_name, kidvec});
                        break;
                    }
                }
                break;
            case 'N':
                new_family = false;
                break;
            default:
                break;
        }
    }

    std::cout << "\n\nCool!"
              << "\nSo we have:" << std::endl;
    decltype(family)::size_type count = 1;
    for (const auto &each : family) {
        std::cout << "\nFamily " << count++ << " - " << each.first
                  << " has the following kids:";
        std::vector<std::string>::size_type cnt = 1;
        for (const auto &kid_name : each.second)
            std::cout << "\n\t\t" << cnt++ << " - "
                      << kid_name.first << " - " << kid_name.second 
                      << " years.";
    }

    std::cout << "\n\nPretty cool, huh?\n" << std::endl;
    return 0;
}


void inline
clear_cin(void)
{
    std::cin.clear();
    while (std::cin.get() != '\n');
}