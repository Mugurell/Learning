/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 11 iunie 2015, 16:33:47 +0300
**  Last updated:     		---
**
**  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**	 (g++ 5.1)		  -Woverloaded-virtual -Winvalid-pch -Wcast-align
**					  -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**					  -Wmissing-format-attribute -Wmissing-include-dirs  
**					  -Wredundant-decls -Wswitch-default -Wswitch-enum  
**
**  Execution:    ./...
**
**  Description:
**  Exercise 10.20: The library defines an algorithm named count_if. Like
**	find_if, this function takes a pair of iterators denoting an input range
**	and a predicate that it applies to each element in the given range. 
**	count_if returns a count of how often the predicate is true. 
**	Use count_if to rewrite the portion of our program that counted how many
**	words are greater than length 6.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  --- You can write here the execution command & the expected result --- 
**
**  Notes:
**  --- 
**
*******************************************************************************
******************************************************************************/



#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	std::cout << std::unitbuf;		// flush the buffer after every output.

	std::vector<std::string> sentence = {"the", "quick", "red", "fox", "jumps",
									"over", "the", "slow", "red", "turtle"};

	std::cout << "\nSo we have a nice little sentence stored in a vector:\n\t";
	std::for_each(sentence.cbegin(), sentence.cend(),
				[](std::string word) { std::cout << word << ' '; });

	std::cout << "\n\nNow let's see how many words with >=6 chars are in it.."
			  << "\n\t";

// make sure there will be no duplicates
	std::stable_sort(sentence.begin(), sentence.end());

	std::vector<std::string>::const_iterator first_dupe;
	first_dupe = std::unique(sentence.begin(), sentence.end());

	sentence.resize(std::distance(sentence.cbegin(), first_dupe));

// print only the words with >=6 chars
	std::for_each(sentence.cbegin(), sentence.cend(),
				[](const std::string word)
				{ if (word.size() >= 6) std::cout << word << ' '; });

	std::cout << "\n\nPretty cool, huh?\n" << std::endl;
	return 0;
}