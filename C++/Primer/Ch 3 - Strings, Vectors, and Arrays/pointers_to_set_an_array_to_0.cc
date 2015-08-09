/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 5 mai 2015, 20:56:41 +0300
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
**  Exercise 3.35: Using pointers, write a program to set the elements in an
**	array to zero.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  --- Anything that stands out ---
**  --- Or needs to be treated with special attention ---
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <iterator>

int main() 
{
	int arr[10];

	std::cout << "\nSo first we had an empty array, default initialized" \
			  << "\n(because it was defined in main):" << std::endl;
	unsigned count {0};
	for (auto x : arr)
		std::cout << "\nElement " << count << " - " << x;

	std::cout << "\n\nBut after filling it with the help of pointers and " \
			  << "iterators, now we have:" << std::endl;
	count = 0;
	for (auto beg = std::begin(arr), end = std::end(arr); beg < end; count++) {
		*beg = count;
		std::cout << "\nElement " << count << " - " << *beg;
		beg = std::next(beg);		
	}

	std::cout << '\n' << std::endl;
	return 0;
}