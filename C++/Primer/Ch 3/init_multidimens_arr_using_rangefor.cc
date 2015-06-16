/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 6 mai 2015, 13:48:35 +0300
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
**  Under the new standard we can replace the old method (2 nested for loops)
**	with 2 smaller range for loops. 
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**	To use a multidimensional array in a range for, the loop control variable 
**	for all but the innermost array must be references.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <iterator>

int main()
{
	std::cout << "\nLet's say we have an array with 3x4 ints." << std::endl;
	int arr[3][4];
	if (std::begin(arr) == std::begin(arr))
		std::cout << "Which is empty to start with.." << std::endl;
	else
		for (auto x : arr)
			std::cout << ' ' << x;

	std::cout << "\nNow if we initialize it using 2 range for nested loops" \
			  << " we'll have.." << std::endl;

	unsigned nr {0}; 
	for (auto &row : arr) {				// for every row in arr
		for (auto col : row) {			// for every column in arr
			col = nr;					// init that elm with a nr
			if ((nr % 4) == 0)			// if we allready have 4 numbers
				std::cout << '\n';		// newline - delimitate rows
			std::cout << " " << col;	// print the element
			nr++;						// increment the nr
		}
	}


	std::cout << '\n' << std::endl;
	return 0;
}