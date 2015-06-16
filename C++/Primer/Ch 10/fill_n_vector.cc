/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 9 iunie 2015, 16:38:49 +0300
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
**  Exercise 10.6: Using fill_n, write a program to set a sequence of int
**	values to 0.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  - take an empty vector and create new elements with value = 0,
**	using an inserter.
**	- copy the elements from the vector into a list, but replace all elements
**	with value 0 with a new value, in this case - 7.
**
**  Notes:
**	- fill_n() is a much more elegant way of initilizing a seq container than 
**	using a ranged for.
**  - replace_copy - another beautifull function, used as a bonus.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <list>
#include <iterator>		// necessary for back_inserter
#include <algorithm>	// necessary for replace_copy()


int main()
{
	std::cout << "\nSo we got ourself a nice pretty little empty vector "
			  << "of ints:\n\tint_vector: ";

	std::vector<int> int_vector;
	if (int_vector.empty())
		std::cout << "<empty>" << std::endl;

	std::cout << "\nNow we'll store in it 10 ints, each with the value 0."
			  << "\n\tint_vector: ";

	// back_inserter() will call vector::push_back(), but 
	// on an inserter, not on an iterator, hence, we'll be able
	// to create new elements in the vector
	std::fill_n(std::back_inserter(int_vector), 10, 0);

	for (short nr : int_vector)
		std::cout << nr << ' ';

	std::cout << "\n\nAnd now, as a bonus, we'll use replace_copy() "
			  << "(also with a back_inserter)\nto create a new list of ints "
			  << "as a copy of the elements in the vector,\n"
			  << "but with it's values replaced to 7.\n\tint_list: ";

	std::list<int> int_list;
	// Starting at int_vector.cbegin(), copy the elements from int_vector
	// into int_list (using push_back() called on a back_inserter()).
	// If any element == 0, replace it with 7 and continue
	// until int_vector.cend().
	std::replace_copy(int_vector.cbegin(), int_vector.cend(),
					  std::back_inserter(int_list), 0, 7);

	for (short nr : int_list)
		std::cout << nr << ' ';

	std::cout << '\n' << std::endl;
	return 0;
}