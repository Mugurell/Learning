/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 7 mai 2015, 18:14:53 +0300
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
**  Exercise 4.21: Write a program to use a conditional operator to find the
**	elements in a vector<int> that have odd value and double the value of
**	each such element.
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

int main()
{
	std::cout << "\nEnter a few numbers separated by spaces :" << std::endl;
	int nr;
	std::vector<int> number;
	while (std::cin >> nr)
		number.push_back(nr);

	std::cin.clear();
	while (std::cin.get() != '\n');

	std::cout << "\n\nSo we have \n\t";
	for (auto beg = number.begin(), end = number.end(); beg != end; ++beg) {
		std::cout << ' ' << *beg;
	} 

	// Test to see if the standard input was cleared.
	std::cout << "\n\nDo you want to continue? [Y] / [N] : ";
	char response;
	std::cin >> response;
	(response >= 'a' && response <= 'z') ? response -= 'a' - 'A' : 1;
	switch (response) {
		case 'Y': break;
		default : return 0;
	}

	std::cout << "\n\nNow if we double each odd number in the vector we'll" \
			  << " have..\n\t";
	for (auto x : number) {
		(x % 2) ? x  *= 2 : 1 ;
		std::cout << ' ' << x;
	}

	std::cout << '\n' << std::endl;
}