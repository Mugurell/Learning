/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 15 mai 2015, 16:33:58 +0300
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
**  Exercise 6.33: Write a recursive function to print the contents of a vector
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

using Iter = const std::vector<char>::iterator;

void print(Iter, Iter);

int main()
{
	gnome-terminal --geometry=100x35+10+10
	
	std::cout << "\nLet's say we have a vector of chars.." << std::endl \
			  << "We'll print that using a recursive function." << std::endl;

	std::vector<char> hello {'\n', '\t', 'H', 'e', 'l', 'l', 'o', ' ', \
							'W', 'o', 'r', 'l', 'd', ' ', '!', '\n', '\n'};
	print(hello.begin(), hello.end());

	return 0;
}

void print(Iter beg, Iter end)
{
	if (beg != end) {
		std::cout << *beg;
		print(std::next(beg), end);
	}
}