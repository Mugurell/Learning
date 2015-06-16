/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 2 iunie 2015, 21:26:47 +0300
**  Last updated:     mari 2 iunie 2015, 21:31:59 +0300
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
**  Exercise 9.14: Write a program to assign the elements from a list of char* 
**	pointers to C-style character strings.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  -C-style character strings should use const char*, otherwise warning:
**	" error: ISO C++ forbids converting a string constant to ‘char*’ 
**	[-Werror=pedantic] std::list< char*> olds {"Ion", "Ionel", "Ionut"}; "
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <vector>
#include <list>


int main()
{
	std::list<const char*> olds {"Ion", "Ionel", "Ionut"};
	std::vector<std::string> news;

	std::cout << "\n\nSo we have a stl list of char* - olds:" << std::endl;
	for (auto nume : olds)
		std::cout << '\t' << nume << std::endl;

	std::cout << "\nAnd a vector of strings - news:" << std::endl;
	if (news.begin() == news.end())
		std::cout << '\t' << "<empty>" << std::endl;
	else
		for (auto nume : news)
			std::cout << "\"\"" << nume << std::endl;

	std::cout << "\nAfter we do \"news = assign(olds.cbegin(), olds.cend()\""
			  << "\nwe'll get to have - olds:\n";
	news.assign(olds.cbegin(), olds.cend());
	for (auto nume : olds)
		std::cout << '\t' << nume << std::endl;

	std::cout << "\nAnd the vector of strings - news:" << std::endl;
	for (auto nume : news)
		std::cout << '\t'<< nume << std::endl;

	std::cout << '\n' << "Remember to remember!\n" << std::endl;
	return 0;
}