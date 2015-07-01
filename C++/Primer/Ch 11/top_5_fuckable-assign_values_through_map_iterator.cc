/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 19 iunie 2015, 19:27:38 +0300
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
**  Exercise 11.16: Using a map iterator write an expression that assigns a
**  value to an element.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None ---  
**
**  Notes:
**  What's important to remember, is that map::iterator will always get us a
**  reference of std::pair<const key, value> 
**  SO THE KEY IS READ-ONLY, BUT THE VALUE IS WRITABLE THROUGH AN ITERATOR !!!
**  (set::iterator will always get us a const iterator for a const value
**      <=> KEYS IN A SET ARE READ-ONLY !!!! )
**
**  Also to be remembered: if we want to insert into a new map, we must
**  remember that the element type is a pair(const key, object). 
**  For ex: map.insert(make.pair(key, object));
**
**  Scott Meyer recommends using emplace, so that's what I used.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <map>
#include <string>
#include <vector>


int main()
{
    std::cout << "\n Please write the name of top 5 girls you'd like to fuck:"
              << std::endl;

    std::map<short unsigned, std::string> top;
    short unsigned count = 1;
    std::string name;

    while (count < 6) {
        std::cout << '\t';
        std::cin >> name;
        top.emplace(count++, name);
    }

    std::cout << "\n\nSo your top is.. !?:";
    for (const auto &each_girl : top)
        std::cout << "\n\t" << each_girl.first << " - " << each_girl.second;

    std::cout << "\n\nYou sure??\n" << "\nHow about..:";
    std::vector<std::string> new_top {"Maria", "Ioana", "Ana", "Banana\n\t\t&", 
                                        "Cosanzeana"};
    std::map<short unsigned, std::string>::iterator it = top.begin();
    std::vector<std::string>::const_iterator vec = new_top.cbegin();
    while (it != top.end()) {
        it->second = *vec;
        it++; vec++;
    }
    for (const auto &each_girl : top)
        std::cout << "\n\t" << each_girl.first << " - " << each_girl.second;

    std::cout << "\n\nHa ha!\nHa!\n\tHa ha!\n" << std::endl;
    return 0;
}
