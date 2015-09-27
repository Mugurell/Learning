/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 5 mai 2015, 14:36:50 +0300
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
**  Decltype cand are argument un array imi returneaza un array cu acelasi nr
**	de elemente, pe cand auto imi returneaza un pointer catre primul element
**	din arrayul primit ca initializator.
**
*******************************************************************************
******************************************************************************/


#include <iostream>

int main()
{
	int arr1[] {1,2,3,4,5};

	decltype(arr1) arr2 [5];
	*arr3 = 2;
	auto arr3 = arr2;
	*arr3 = 3;
	std::cout << "arr2 is " << *(arr2+3) << std::endl;
	std::cout << "arr3 is " << *(arr3+3) << std::endl;

	return 0;
}