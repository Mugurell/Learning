/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 10 iunie 2015, 21:53:49 +0300
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
**  Exercise 10.19: Rewrite the previous exercise to use stable_partition,
**	which like stable_sort maintains the original element order in the 
**	paritioned sequence
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  	The library defines an algorithm named partition that 
**	takes a predicate and partitions the container so that values for which
**	the predicate is true appear in the first part and those for which the
**	predicate is false appear in the second part. The algorithm returns an
**	iterator just past the last element for which the predicate returned true.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



int main()
{
	std::cout << std::unitbuf;		// flush the buffer after every output.

	std::vector<std::string> sentence = {"the", "quick", "red", "fox", "jumps",
									"over", "the", "slow", "red", "turtle"};
	std::vector<std::string>::size_type orig_size = sentence.size();

	std::cout << "\nSo we have a nice little sentence stored in a vector:\n\t";
	std::for_each(sentence.cbegin(), sentence.cend(),
				[](const std::string &word) { std::cout << word << ' '; });

	std::cout << "\n\nWe'll now partition this vector so to focus on just"
			  << "\nwords that have >=5 characters:\n\t.........";

	std::vector<std::string>::const_iterator first_smaller;
	first_smaller = stable_partition(sentence.begin(), sentence.end(),
						[](std::string word) { return word.size() >= 5; });


	std::cout << "\n\nSo the words with >= 5 chars are:\n\t";
	std::for_each(sentence.cbegin(), first_smaller,
			[](const std::string &word) { std::cout << word << ' '; });

	std::cout << "\n\nAnd the words with <5 chars are:\n\t";
	std::for_each(first_smaller, sentence.cend(),
			[](const std::string &word) { std::cout << word << ' '; });


	std::cout << '\n' << std::endl;
	return 0;

}