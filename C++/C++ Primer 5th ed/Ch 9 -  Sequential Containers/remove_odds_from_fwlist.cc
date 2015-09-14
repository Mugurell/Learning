/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 4 iunie 2015, 17:28:18 +0300
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
**  Exercise 9.27: Write a program to find and remove the odd-valued
**	elements in a forward_list<int>.
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
#include <forward_list>


int main()
{
	std::forward_list<int> list = {0,1,2,3,4,5,6,7,8,9};

	std::cout << "\nSo I have a nice little fwlist of ints:"
			  << "\n\t list: ";
	for (int nr : list)
		std::cout << nr << ' ';

	std::forward_list<int>::iterator curr = list.begin();
	std::forward_list<int>::iterator prev = list.before_begin();

	while (curr != list.end()) {
		if (*curr % 2)
			// will erase the curr and return a pointer to the next element
			curr = list.erase_after(prev);
		else {
			prev = curr;	// same as prev++
			curr++;
		}
	}

	std::cout << "\n\nIf I am to erase it's odd elements,"
			  << " I'd end up with: ";
	for (auto nr : list)
		std::cout << nr << ' ';


	std::cout << '\n' << std::endl;
	return 0;
}