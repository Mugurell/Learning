/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          		---
**  Last updated:     		---
**
**  Compilation:  g++ -std=gnu++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**	 (g++ 5.1)		  -Woverloaded-virtual -Winvalid-pch -Wcast-align
**					  -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**					  -Wmissing-format-attribute -Wmissing-include-dirs  
**					  -Wredundant-decls -Wswitch-default -Wswitch-enum  
**
**  Execution:    ./...
**
**  Description:
**  Concentrate a list of grades into a nice aaray
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
**  - When using a variable as a subscript for an array, that variable should
**	normally be defined as a size_t (long unsigned int).
**	size_t type is defined in cstddef - the c++ version of the stddef.h from C.
**	- If in a function (even main) unitialized variables will get automagically
**	contain junk - undefined. Declare them outside of any f. or initialize em.
*******************************************************************************
******************************************************************************/



#include <iostream>
#include <cstddef>		//necessary for size-t type

int main()
{
	unsigned grades[11] = {};		// 11 grades initialized to 0
	size_t grade;

	std::cout << "\nWe start with the counter is at 0\n\t";
	for (size_t x : grades)
		std::cout << ' ' << x;

	std::cout << "\n\nPlease enter the list of grades" << std::endl;
	while (std::cin >> grade)
		if (grade <= 100)
			++grades[grade/10];

	std::cout << "\nThe formatted list of grades is\n\t";
	for (auto x : grades)
		std::cout << ' ' << x;

	std::cout << '\n' << std::endl;

	return 0;
}