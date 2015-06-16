/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 5 iunie 2015, 15:55:34 +0300
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
**  Exercise 9.41: Write a program that initializes a string from a
**	vector<char>.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**
**  Notes:
**  ---
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <vector>


int main()
{
	std::vector<char> vc = {'A', 'n', 'a', ' ', 'a', 'r', 'e', ' ', 
							'm', 'e', 'r', 'e', '.', '\0'};

	std::cout << "\nSo we have a nice little vector of chars:\n\t";
	for (char ch : vc) std::cout << ch;

	std::cout << "\n\nIf we're to initialize a string from this vector..";
	std::string st(vc.begin(), vc.end());
	std::cout << "\nwe'd get a string with " << st.size() << " elements:\n\t";
	for (auto ch : st) std::cout << ch;

	std::cout << '\n' << std::endl;
	return 0;
}