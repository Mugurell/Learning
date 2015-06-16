/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 12 mai 2015, 19:29:00 +0300
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
**  Exercise 5.21: Write a program to check for duplicated words that start 
**	with an uppercase letter and print the highest # of identical strings.
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
**  --- Anything that stands out ---
**  --- Or needs to be treated with special attention ---
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <cctype>		// necesar pt isupper

int main()
{
	std::vector<std::string> prop;
	std::string cuv;
	bool found_identical_word = false;

	std::cout << std::endl;
	while (std::cin >> cuv && cuv != "quit") {
		if (!prop.empty()) {
			for (auto word : prop)
				if (word == cuv) {
					std::cout << "\n\tBingo !" << "\nWe have 2 " << cuv \
							  << '\n' << std::endl;
							  found_identical_word = true;
							  break;	// break from the for range loop.
				}
		} else if (isupper(cuv[0])) 
			prop.push_back(cuv);
		if (found_identical_word)
			break;		// break from the while loop.
	}

	if (!found_identical_word)
		std::cout << "\nNo identical words found!\n" << std::endl;

	return 0;
}