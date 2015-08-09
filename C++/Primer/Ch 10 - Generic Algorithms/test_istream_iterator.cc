/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 12 iunie 2015, 20:01:17 +0300
**  Last updated:     sâmbt 13 iunie 2015, 18:09:18 +0300
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
**  Exercise 10.29: Write a program using stream iterators to read a text file
**	into a vector of strings.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  Read "read_cin_using_iterators.cc" for a more elegant implementation ;-)
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


int main()
{
	std::cout << "\n\nFirst we'll gonna open a presetted file with some text,"
			  << "\nwhich will be read using an istream iterator."
			  << std::endl;

	std::ifstream inputFile("text.txt");
	std::vector<std::string> txt_read;
	if (inputFile.is_open()) {
		std::istream_iterator<std::string> in_str(inputFile);
		std::istream_iterator<std::string> gicu;	// will serve as
													// off-the-end iterator

// this is where the magic happend
		while (in_str != gicu)	// while there's input to read
			// postfix increment reads the stream and returns the old value
			//			of the iterator
			// we dereference that iterator to get the previous value read
			//			from the stream
			txt_read.push_back(*in_str++);

	} else {
		std::cerr << "\n\nError: Couldn't open file!\n" << std::endl;
	}

	std::cout << "\nAnd we read..:\n\"";
	std::for_each(txt_read.cbegin(), txt_read.cend(),
					[](const std::string &word) { std::cout << word << ' '; });

	std::cout << "\"\n\nPretty cool, right?\n" << std::endl;

	return 0;
}