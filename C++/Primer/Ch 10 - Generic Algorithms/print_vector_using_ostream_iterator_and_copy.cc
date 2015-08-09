/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          		---
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
#include <iterator>
#include <algorithm>


int main()
{
	std::vector<int> vint = {1, 2, 3, 4, 5};
	std::ostream_iterator<int> ostream_iterator(std::cout, " ");

	std::cout << "\nSo we have a vector of ints which we'll print using\n"
			  << "std::copy(vec.cbegin(), vec.cend(), ostream_iterator)"
			  << "\n\n\t";

	std::copy(vint.cbegin(), vint.cend(), ostream_iterator);

	std::cout << "\n\nPretty cool, huh?\n" << std::endl;
	return 0;
}