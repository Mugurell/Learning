/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 9 iunie 2015, 18:18:29 +0300
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
**  --- This is a description of what the program does ---
**
**  Bugs:
**  The sentence_copy vector contains only one string which has all the 
**	words from the array. Not one string for an array.
**	Need to split it somehow...
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
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>


int main()
{
	std::cout << std::unitbuf;

	const char *sentence[] = {"the quick red fox jumps over the slow red turtle"};

	std::cout << "\nSo we got a nice pretty c-style array:\n\tsentence: "
			  << *sentence
			  << "\n\nWill copy this into a vector, "
			  << "\nthan use std::find() to search for duplicate words,"
			  << "\nand save only the once-repeated in a new vector"
			  << "\n\tvector: ";

	//std::vector<std::string> sentence_copy(sentence, std::end(sentence));

	std::vector<std::string> sentence_copy = {"the", "quick", "red", "fox",
								"jumps", "over", "the", "slow", "red", "turtle"};
	std::vector<std::string> clean_sentence;

// test to see how many strings does sentence_copy has.
//	std::cout << "\n sentence_copy are " << sentence_copy.size() << " element.\n";


	for (std::string word : sentence_copy) {
		if (clean_sentence.end() != std::find(std::begin(clean_sentence), 
											   std::end(clean_sentence), word))
			continue;
		else
			std::fill_n(std::back_inserter(clean_sentence),1 ,word);
	}

	for (std::string word : clean_sentence)
		std::cout << word << ' ';

	std::cout << '\n' << std::endl;

	return 0;		  
}