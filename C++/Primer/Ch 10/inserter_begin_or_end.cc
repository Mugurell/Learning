/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 12 iunie 2015, 17:14:53 +0300
**  Last updated:     vineri 12 iunie 2015, 17:19:54 +0300
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
**  Test inserter(list, list.begin()) / inserter(list, list.end()) to try to
**	understand what position the returned iterator will indicate.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  Hmmm... I still don't know what position the iterator returned by inserter
**	will be at(front/exact/over the position of the inserted element).
**		cppreference.com says that the inserter will insert a new object at the
**	position passed by iterator, and the iterator returned will point to the
**	newly inserted iterator...
**
*******************************************************************************
******************************************************************************/


#include <iostream>
using std::cout; using std::endl; using std::unitbuf;

#include <iterator>
using std::inserter; using std::front_inserter;

#include <list>
using std::list;

#include <algorithm>
using std::copy;


int main()
{
	cout << unitbuf;	// flush buffer after every output

	cout << "\nSo we have a nice little list of ints:\n\t";
	list<int> lint1= {1, 2, 3, 4, 5}, lint2, lint3, lint4;
	for (const int &nr : lint1)
		cout << nr << ' ';

	cout << "\n\nIf we're using front_inserter to copy 'em in a new list"
		 << ", we'll have:\n\t";

	copy(lint1.cbegin(), lint1.cend(), front_inserter(lint2));
	for (const int &nr : lint2)
		cout << nr << ' ';

	cout << "\n\nAnd if we'd use an inserter(list, list.begin()),"
		 << " we'd have:\n\t";
	copy(lint1.begin(), lint1.end(), inserter(lint3, lint3.begin()));
	for (const int &nr : lint3)
		cout << nr << ' ';

	cout << "\n\nAnd if we'd use an inserter(list, list.end()),"
		 << " we'd have:\n\t";
	copy(lint1.cbegin(), lint1.cend(), inserter(lint4, lint4.end()));
	for (const auto &nr : lint4)
		cout << nr << ' ';

	cout << "\n\nCool, huh" << endl;
	return 0;
}