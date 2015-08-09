/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          duminic 14 iunie 2015, 20:33:52 +0300
**  Last updated:     		---
**
**  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**                    -Wmissing-format-attribute -Wmissing-include-dirs  
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
**
**  Execution:    ./...
**
**  Description:
**  Exercise 10.37: Given a vector that has ten elements, copy the elements
**	from positions 3 through 7 in reverse order to a list.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  The list will only have 7 6 5 4 3
**
**  Notes:
**  --- 
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>


int main()
{
	std::cout << std::unitbuf;
	std::ostream_iterator<int> print(std::cout, " ");

	std::vector<int> vint;
	for (int nr = 0; nr != 10; nr++)
		vint.push_back(nr);

	std::cout << "\nSo we have a nice little vector of ints:\n\t";
	for (auto nr : vint) std::cout << nr << ' ';


	std::cout << "\n\nAnd after copying elements 3-7 from the vector"
			  << "\nto a new list, that would contain..:\n\t" << std::endl;

	std::list<int> lint;
	std::copy(vint.crbegin()+2, vint.crend()-3, std::back_inserter(lint));

	for (const int &nr : lint) print = nr;

	std::cout << "\n\nLint are " << lint.size() << " elemente.";

	std::cout << "\n\nPretty cool, huh?\n" << std::endl;

	return 0;
}