/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          luni 15 iunie 2015, 21:29:33 +0300
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
**  The list and forward_list have a particular algorithm - splice().
**	There is not a generic version of it does not exist.
**	It will move elements from the rightmost arguments into the leftmost one.
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
**  Splice will move the elements from list 2 to list 1/
**	Hence, list 2 will not have access to those elements again!
**	If splice all elements of list 2, that list will remain empty!
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>


int main()
{
	std::list<int> lint1, lint10;
	for(int i = 0; i != 10; i++) {
		lint1.insert(lint1.end(), i);
		lint10.push_back(i*10);
	}

	std::cout << "\nSo we have 2 nice little lists of ints:\n\t";

	std::ostream_iterator<int>  print(std::cout, "  ");
	for (const int &nr : lint1) 
		print = nr;
	std::cout << "\n\t";

	std::for_each(lint10.cbegin(), lint10.cend(), 
				[&](const int &nr) { std::cout << nr << ' '; });

	std::cout << "\n\nNow we'll use"
			  << "\n\tlint1.splice(lin1.end(), lint10)"
			  << " which will gove us:\n\t";
	lint1.splice(lint1.end(), lint10);
	std::copy(lint1.cbegin(), lint1.cend(), print);

	std::cout << "\n\nPretty cool, huh?\n" << std::endl;

}