/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 12 iunie 2015, 17:31:39 +0300
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
**  Exercise 10.27: In addition to unique (§ 10.2.3, p. 384), the library
**	defines function named unique_copy that takes a third iterator denoting a
**	destination into which to copy the unique elements. Write a program that
**	uses unique_copy to copy the unique elements from a vector into an
**	initially empty list
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
using std::cout; using std::endl; using std::unitbuf;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <algorithm>
using std::unique_copy; using std::for_each;

#include <iterator>
using std::back_inserter;


int main()
{
	cout << unitbuf;	// flush buffer after every output

	cout << "\nSo we have a nice little list of ints:\n\t";
	list<int> lint1= {1, 2, 2, 3, 4, 4, 5};
	for (const int &nr : lint1)
		cout << nr << ' ';

	cout << "\n\nNow we'll gonna use unique_copy to copy unique elements"
		 << "\nfrom the list to a new, initially empty vector of ints..";
	vector<int> vint;
	unique_copy(lint1.cbegin(), lint1.cend(), back_inserter(vint));
	cout << "\n\nAnd so, we'll have\n\t";
	for_each(vint.cbegin(), vint.cend(),
		 	[](const int &nr) { cout << nr << ' '; });

	cout << "\n\nPretty cool, huh\n" << std::endl;
	return 0;
}