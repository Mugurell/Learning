/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 9 iunie 2015, 21:56:57 +0300
**  Last updated:     miercuri 10 iunie 2015, 17:37:28 +0300
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
**  Exercise 10.13: The library defines an algorithm named partition that 
**	takes a predicate and partitions the container so that values for which
**	the predicate is true appear in the first part and those for which the
**	predicate is false appear in the second part. The algorithm returns an
**	iterator just past the last element for which the predicate returned true.
**	Write a function that takes a string and returns a bool indicating whether
**	the string has five characters or more. Use that function to partition
**	words. Print the elements that have five or more characters.
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
**  used a lambda instead of five_or_more().
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


bool five_or_more(const std::string&);
inline void print_sentence(const std::vector<std::string>&);

int main()
{
	std::cout << std::unitbuf;		// flush the buffer after every output.

	std::vector<std::string> sentence = {"the", "quick", "red", "fox", "jumps",
									"over", "the", "slow", "red", "turtle"};
	std::vector<std::string>::size_type orig_size = sentence.size();

	std::cout << "\nSo we have a nice little sentence stored in a vector:\n\t";
	print_sentence(sentence);

	std::cout << "\n\nWe'll now partition this vector so to focus on just"
			  << "\nwords that jave >= characters:\n\t";
	std::vector<std::string>::const_iterator less_than_five;
	less_than_five = std::partition(sentence.begin(), sentence.end(),
									[](const std::string &word)
										{ return word.size() >= 5; });
	print_sentence(sentence);

	std::cout << "\n\nAnd if we're to remove the words with fewer than 5 "
			  << "characters,\nwe'd be left with just:\n\t";
	sentence.erase(less_than_five, sentence.end());
	print_sentence(sentence);

// addition.
// print how many words are there over a certain char limir
// use lambda
	std::vector<std::string>::difference_type diff = 
												orig_size - sentence.size();
	std::cout << "\n\nSo there are " << diff
			  << [diff] {return (diff == 1)? "word" : "words";}
			  << " with more than 5 chars..";

	std::cout << '\n' << std::endl;
	return 0;
}


bool
five_or_more(const std::string &word)
{
	return word.size() >= 5;
}


inline void
print_sentence(const std::vector<std::string> &sentence)
{
	for (const std::string &word : sentence)
		std::cout << word << ' ';	
}