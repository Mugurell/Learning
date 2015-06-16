/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 12 mai 2015, 15:39:29 +0300
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
**  Exercise 5.19: Write a program that uses a do while loop to repetitively
**	request two strings from the user and report which string is less than
**	the other.
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
**  DO NOT try to store a string using 'cin >> string' ! 
**	Use getline(,) if you want to store your sentence in a string,
**	Or use sentence.push_back(word) if you store your sentence in a vector !!!
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>

using std::string;

int main()
{
	std::string s1, s2, response;

/*	std::cout << "\nS1 e \"" << s1 << "\", iar s2 e \"" << s2 << '\"' \
			  << '\n' << std::endl;*/

	do {
		std::cout << "\nSay something:" << std::endl;
		getline(std::cin, s1);
		std::cout << "\nOne more time:" << std::endl;
		getline(std::cin , s2);

		std::cout << "\n Based on my calculations..." << std::endl;
		if (s1.size() > s2.size()) {
			std::cout << "The first string is bigger than the second!" \
					  << std::endl;
			std::cout << "S1 are " << s1.size() << ", iar s2 - " \
					  << s2.size() << std::endl;
		}
		else if (s1.size() < s2.size())
			std:: cout << "The second string is bigger than the first!" \
					   << std::endl;
		else 
			std::cout << "Both strings entered are equal in size!" << std::endl;

		std::cout << "Wanna try again? [Y] / [N] : ";
		std::cin >> response;
	} while (!response.empty() && response[0] != 'N' && response[0] != 'n');

	return 0;
}
