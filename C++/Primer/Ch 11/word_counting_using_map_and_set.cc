/******************************************************************************
*******************************************************************************
**
**  uthor:           Lingurar Petru-Mugurel
**  Written:         miercuri 17 iunie 2015, 21:18:00 +0300
**  Last updated:     		---
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
**  Exercise 11.3: Write your own version of the word-counting program.
**  Exercise 11.4: Extend your program to ignore case and punctuation. For
**  example, “example.” “example,” and “Example” should all increment the same
**  counter.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  See https://en.wikipedia.org/wiki/Erase-remove_idiom
**
*******************************************************************************
******************************************************************************/



#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstddef>		// for size_t
#include <algorithm>	// for_each()
#include <iterator>		// for ostream_iterator
#include <cctype>       // for tolower(), ispunct()



int main()
{
	std::cout << "\nLet's play a game:"
              << "I have some words, with are forbidden for you to use:\n\t";
	std::set<std::string> no_set = {"This", "is", "not", "a", "test"};
	for (const std::string &w : no_set)
		std::cout << w << ' ';

	std::cout << "\n\nNow you can write whatever you like,\n"
	          << "I'll compare what you'll say with the \"forbidden words\"\n"
              << "and see what we're left with..\n" << std::endl;

	std::map<std::string, std::size_t> input_words;
	std::map<std::string, std::size_t> bad_words;
	std::string word;
	while (std::cin >> word) {
        for (auto &ch : word) 
            ch = tolower(ch);
        
// the erase-remove idiom
        word.erase(std::remove_if(word.begin(), word.end(), isdigit),
                                     word.end());
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), 
                                    word.end());

// check if the word is one of the ones that "should not be typed"
		if (no_set.find(word) == no_set.end())
			++input_words[word];
		else
			++bad_words[word];
	}


	std::cout << "\n\nCool man!" << std::endl;
	if (bad_words.size() > 0 && input_words.size() > 0) {
	    std::cout << "Although you said some bad words:" << std::endl;
	    for (const auto &w : bad_words)
            std::cout << "\tWord " << w.first << " - " << w.second
                      << ((w.second > 1) ? " times" : " time") << std::endl; 

        std::cout << "\nYou've demonstrated you have a rich vocabulary "
                  << "by using:" << std::endl;
        for (const auto &w : input_words)
            std::cout << "\tWord " << w.first << " - " << w.second
                      << ((w.second > 1) ? " times" : " time") << std::endl; 
	} else
        std::cout << "\n\nPfff\n\n\tBye\n" << std::endl;


	          
	return 0;
}