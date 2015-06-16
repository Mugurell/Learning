/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 2 iunie 2015, 22:45:28 +0300
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
**  Exercise 9.16: Compare elements in a list<int> to a vector<int>.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  Will say the vector is bigger because although it has fewer elements, on
**	the same position - 2, the vector has 4 and the list has 3.
**	Hence, the vector is bigger!
**
**  Notes:
**  Pay attention to how I formed an vector of ints from the range of begin()
**	and end() iterators of list!
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <list>


int main()
{
	std::list<int> list {1, 2, 3, 4, 5};
	std::vector<int> vector {1, 2, 4};

	std::cout << "Let's say we have a\nlist of ints: ";
	for (auto nr : list)
		std::cout << nr << ' ';
	std::cout << "\n\nAnd a vector of ints: ";
	for (auto nr : vector)
		std::cout << nr << ' ';

	std::cout << "\nGuess who's bigger?" << std::endl;
	if ((std::vector<int>(list.begin(), list.end())) == vector)
		std::cout << "Both are actually equal!" << std::endl;
	else 
		std::vector<int>(list.begin(), list.end()) < vector
			? std::cout << "The vector is bigger than the list!\n" << std::endl
			: std::cout << "The vector is smaller than the list!\n" 
			<< std::endl;

	return 0;
}