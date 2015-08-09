/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 5 iunie 2015, 22:32:42 +0300
**  Last updated:     vineri 5 iunie 2015, 22:59:24 +0300
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
**  Exercise 9.49: A letter has an ascender if, as with d or f, part of the
**	letter extends above the middle of the line. A letter has a descender if,
**	as with p or g, part of the letter extends below the line. Write a program
**	that reads a file containing words and reports the longest word that
**	contains neither ascenders nor descenders.
**
**  Bugs:
**  I think it might ommit the last inserted word.
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  --- You can write here the execution command & the expected result --- 
**
**  Notes:
**  std::noskipws as to not skip white spaces
**	I've included the space, \n, \t in the 'std::string normal' because in the
**	ranged for the words have spaces as a character. If I would not have
**	included white space, the otherwise normal words wouldn't register.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <vector>


int main()
{
	std::string normal(" \n\tacemnorsuvwxz");

	std::cout << "\nWrite something, and I'll tell you if you had any "
			  << "\nascenders or descenders in your printed saying:\n\n";

	std::string word;
	std::vector<std::string> saying;
	char ch;
	while (std::cin && std::cin >> std::noskipws >> ch && ch != '~') {
		if (ch == ' ' || ch == '\t' || ch == '\n') {
			word.push_back(ch);
			saying.push_back(word);
			word.erase();
		}
		else
			word.push_back(ch);
	}
	saying.push_back(word);

	

	std::string longest_word;
	for (auto words : saying) {
		if (words.find_first_not_of(normal) == std::string::npos &&
			words.size() > longest_word.size()) { 

			longest_word = words;
		}
	}

	std::cout << "\n\nSo, the longest normal word was..: "
			  << longest_word << '\n' << std::endl;

	return 0;
}