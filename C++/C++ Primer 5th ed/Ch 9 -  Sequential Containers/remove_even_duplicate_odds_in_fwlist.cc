/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 4 iunie 2015, 21:46:35 +0300
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
**  Removes the evens and duplicate the odd numbers in a forward_list.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**   Exercise 9.31: The program on page 354 to remove even-valued elements
**	and duplicate odd ones will not work on a list or forward_list. Why?
**	Revise the program so that it works on these types as well.
**
**  Notes:
**  Programul original
**	vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
**	auto iter = vi.begin(); // call begin, not cbegin because we're changing vi
**	while (iter != vi.end()) {
**		if (*iter % 2) {
**			iter = vi.insert(iter, *iter); // duplicate the current  element
**			iter += 2; // advance past this elem and the one inserted before it
**		} else
**			iter = vi.erase(iter); // remove even elements
**	// don't advance the iterator; iter denotes the element after the one we
**	erased.
**	
**	Pentru list ar fi mers si in forma asta, pentru forward_list, intervin
**	before_begin(), insert_after(), erase_after().
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <forward_list>


int main()
{
	std::cout << "\nSo we have a nice pretty little fw_list of ints:\n\t";
	std::forward_list<int> li = {0,1,2,3,4,5,6,7,8,9};
	for (int nr : li) std::cout << nr << ' ';

	std::cout << "\n\nAfter removinf the odds and duplicating the evens"
			  << "\n we'll have: ";

	std::forward_list<int>::iterator curr = li.begin();
	std::forward_list<int>::iterator prev = li.before_begin();
	while (curr != li.end()) {
		if (*curr % 2) {	// if odds
			curr = li.insert_after(prev, *curr);
			// advance curr and prev iterators 2 positions
			std::advance(curr, 2);
			std::advance(prev, 2);		
		} else
			curr = li.erase_after(prev);
	}

	for (auto nr : li) std::cout << nr << ' ';

	std::cout << '\n' << std::endl;
	return 0;
}