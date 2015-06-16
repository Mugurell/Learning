/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 13 iunie 2015, 23:06:08 +0300
**  Last updated:     		---
**
**  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**	 (g++ 5.1)         -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                                -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**                                -Wmissing-format-attribute -Wmissing-include-dirs  
**                                -Wredundant-decls -Wswitch-default -Wswitch-enum  
**
**  Execution:    ./...
**
**  Description:
**  Exercise 10.34: Use reverse_iterators to print a vector in reverse order.
**	Exercise 10.35: Now print the elements in reverse order using ordinary
**	iterators
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
**  I dont think "std::prev(numbers.cbegin())" is legal... 
**	Only forward_list has an before_begin iterator
**	This may result in undefined result...
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::vector<int> numbers = {1, 2, 3, 4, 5, 6};

	std::cout << "\nSo here's out vector, printed in reverse order"
			  << " using reverse_iterators:\n\t";
	std::for_each(numbers.crbegin(), numbers.crend(), 
					[](const int &nr) { std::cout << nr << ' '; });

	std::cout << "\n\nAnd here's the vector printed in reverse order"
			  << " using ordinary iterators:\n\t";
/* Read Notes.
	for (auto it = std::prev(numbers.cend()); 
			it != std::prev(numbers.cbegin()); --it){
		std::cout << *it << ' ';
	}
*/
	for (auto it = std::prev(numbers.cend()); ; --it) {
		std::cout << *it << ' ';
		if (it == numbers.cbegin()) break;
	}

	std::cout << "\n\nPretty cool, rite?\n" << std::endl;

}