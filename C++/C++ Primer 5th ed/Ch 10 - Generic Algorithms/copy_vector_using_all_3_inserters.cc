/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 12 iunie 2015, 18:02:37 +0300
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
**  Exercise 10.28: Copy a vector that holds the values from 1 to 9 inclusive,
**	into three other containers. Use an inserter, a back_inserter, and a
**	front_inserter, respectivly to add elements to these containers. Predict
**	how the output sequence varies by the kind of inserter and verify your
**	predictions by running your programs.
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
**  	back_inserter(arg) and front_inserter(arg) will call the
**	push.back  and  push_front  functions of their arg !!!!!!!!!!!!!!
**
*******************************************************************************
******************************************************************************/


#include <iostream>
using std::cout; using std::endl; using std::unitbuf;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <deque>
using std::deque;

#include <forward_list>
using std::forward_list;	// doesn't support reverse_iterators... idk...

#include <iterator>
using std::inserter; using std::back_inserter; using std::front_inserter;

#include <algorithm>
using std::copy; using std::for_each;


int main()
{
	cout << unitbuf;		// flush buffer after every output;

	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> l1;
	deque<int> d1;
	forward_list<int> fw1;

	cout << "\n\nSo we have a nice little vector of ints:\n\t";
	for_each(v1.cbegin(), v1.cend(), [](const int &nr) { cout << nr << ' '; });

	cout << "\n\nNow if we're gonna copy 'em into a new list"
		 << "\nusing inserter, we'll have:\n\t";
	copy(v1.cbegin(), v1.cend(), inserter(l1, l1.begin()));
	for_each(l1.cbegin(), l1.cend(), [](const int &nr) { cout << nr << ' '; });

	cout << "\n\nNow if we're gonna copy 'em into a new deque"
		 << "\nusing back_inserter, we'll have:\n\t";
	copy(v1.cbegin(), v1.cend(), back_inserter(d1));
	for_each(d1.cbegin(), d1.cend(), [](const int &nr) { cout << nr << ' '; });

	cout << "\n\nNow if we're gonna copy 'em into a new forward_list"
		 << "\nusing front_inserter, we'll have:\n\t";
	copy(v1.cbegin(), v1.cend(), front_inserter(fw1));
	for_each(fw1.cbegin(), fw1.cend(),
				[](const int &nr) { cout << nr << ' '; });

	cout << "\n\nPretty cool, huh?\n" << endl;
	return 0;
}