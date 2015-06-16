/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 2 iunie 2015, 17:43:02 +0300
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
**  Test how swap() works.
**
**	Expected result:
**	Will swap the eelements. v1 will have v2's and v2 will have v1's.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  a.Swap(b) will exchange elements in a with those in b.
**	a si b trebuie sa fie de acelasi tip si sa contina acelasi tip de obiecte!
**	, nu neaparat sa aiba si acelasi numar de obiecte!
**	swap is usually much faster than copying elements from b to a.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <deque>


int main()
{
	std::cout << std::unitbuf;
	std::vector<int> v1 {1, 2, 3, 4};
	std::vector<int> v2 {10, 9};

	std::cout << "\nSo I have 2 ints vectors:\n"
			  << "v1:";
	for (auto nr : v1)
		std::cout << '\t' << nr << '\n';
	std::cout << "\nand v2:";
	for (auto nr : v2)
		std::cout << '\t' << nr << '\n';

	std::cout << "\n\nNow if I do v1.swap(v2) I'll have..:\n"
			  << "v1:";
	v1.swap(v2);
	for (auto nr : v1)
		std::cout << '\t' << nr << '\n';
	std::cout << "\nand v2:";
	for (auto nr : v2)
		std::cout << '\t' << nr << '\n';

	std::cout << "\n\nNow what do you think 'bout that?\n" << std::endl;
	return 0;
}