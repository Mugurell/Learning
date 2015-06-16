/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          duminic 14 iunie 2015, 09:08:07 +0300
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
**  Exercise 10.36: Use find to find the last element in a list of ints with
**	value 0.

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
**	reverse_iterator.base() will get us the corresponding ordinary iterator
**  Not quite clear on why the -1 was needed....
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>


int main()
{
	std::list<int> lint = {1, 0, 2, 0, 3, 0, 4, 0, 5};

// print the initial list
	std::cout << "\nSo we have a nice little list of ints...\n\t";
	std::ostream_iterator<int> output_int(std::cout, " ");
	std::for_each(lint.cbegin(), lint.cend(),
				[&](const int &nr) { output_int = nr; });


// find last zero (first in reverse)
// calculate it's distance from beginning to find it's position in the list.
	std::list<int>::const_reverse_iterator last_zero = 
					std::find(lint.crbegin(), lint.crend(), 0);

	std::list<int>::difference_type position=
					std::distance(lint.cbegin(), last_zero.base());
				//	std::distance(last.zero, lint.crend());

	std::cout << "\n\n Awfull lot of zeros there, huh?"
			  << "\nLast zero is at position.. : " << position - 1
			  << "\n\nPretty cool, huh\n" << std::endl;
	return 0;
}