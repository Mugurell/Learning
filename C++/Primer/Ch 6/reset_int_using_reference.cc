/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 14 mai 2015, 11:30:11 +0300
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
**  Exercise 6.11: Write and test your own version of reset that takes a
**	reference.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  --- 
**
**  Notes:
**  --- 
**
*******************************************************************************
******************************************************************************/

#include <iostream>

void reset(int &);

int main()
{
	int x {43};
	std::cout << "\nLet's say we have an int, " << x << '.' << std::endl;
	
	reset(x);
	std::cout << "\nIf we're to reset it's value.., we'd now have " << x  \
			  << ".\n" << std::endl;

	return 0;
}

void reset(int &nr)
{
	nr = 0;
}
