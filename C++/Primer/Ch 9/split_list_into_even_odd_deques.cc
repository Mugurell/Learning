/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 3 iunie 2015, 17:49:55 +0300
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
**  Exercise 9.20: Write a program to copy elements from a list<int> into
**	two deques. The even-valued elements should go into one deque and the
**	odd ones into the other.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  --- 
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <deque>
#include <list>


int main()
{
	std::list<int> list;
	for (int x = 0; x != 20; list.push_back(x++));

	std::cout << "\nLet's say we have a nice little list of ints:" << std::endl;
	for (auto nr : list)
		std::cout << ' ' << nr;


	std::deque<int> odds, even;
	for (auto nr : list)
		nr % 2 == 0 ? even.push_back(nr) : odds.push_back(nr);

	std::cout << "\n\nIf we're to split it in two deques, based on even/odd"
			  << "\nnumbers we'd end up with:"
			  << "\n\nEven numbers:\n\t";
	for (auto nr : even)
		std::cout << nr << ' ';
	
	std::cout << "\n\nOdd numbers:\n\t";
	for (auto nr : odds)
		std::cout << nr << ' ';


	std::cout << "\n\n\tCool, rite?\n" << std::endl;
	return 0;
}
