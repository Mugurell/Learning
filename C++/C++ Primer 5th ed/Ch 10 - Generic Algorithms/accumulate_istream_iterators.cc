/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 13 iunie 2015, 18:23:27 +0300
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
**  Quick and elegant implementation of the relation between
**	some algorithms and istream_iterators.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  std::accumulate(begin_it, end_it, starting value);
**		So freakin elegant!
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <iterator>		// std::istream_iterator
#include <algorithm>	// std::accumulate


int main()
{
	std::cout << std::unitbuf;

	std::cout << "\nEnter some numbers and I'll tell you their sum:\n\t";

	std::istream_iterator<int> numbers(std::cin), eof;

// This is where the magic happens!	
	std::cout << "\n\nSo their sum is...:\n\t"
			  << std::accumulate(numbers, eof, 10);

	std::cout << "\n\nI've thrown in a little something ;-)\n" << std::endl;
	return 0;
}