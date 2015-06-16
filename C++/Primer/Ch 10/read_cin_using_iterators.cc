/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 13 iunie 2015, 18:05:53 +0300-
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
**	Here we construct vec from a pair of iterators that denote a range of
**	elements.Those iterators are istream_iterators, which means that the range
**	is obtained by reading the associated stream. This constructor reads cin
**	until it hits end-of-file or encounters an input that is not an int.
**	The elements that are read are used to construct vec.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  Between the comments there is gold! Read it carefully!
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <iterator>		// istream_iterator
#include <algorithm>	// for_each()


int main()
{
	std::cout << std::unitbuf;

	std::cout << "\nWrite some numbers if you may..:\n\t";

// This is where the magic happens.
// Read it twice!
	std::istream_iterator<int> input_iter(std::cin), eof;
	std::vector<int> numbers(input_iter, eof);
// That thing up there is golden. So elegant!
// Read it again!

	std::cout << "\n\nSo the numbers read were:\n\t";
	std::for_each(numbers.cbegin(), numbers.cend(),
				[](int nr) { std::cout << nr << ' '; });

	std::cout << "\n\nPretty cool, huh?\n" << std::endl;
	return 0;
}