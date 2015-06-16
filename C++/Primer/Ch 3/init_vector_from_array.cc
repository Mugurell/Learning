/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 5 mai 2015, 23:03:51 +0300
**  Last updated:     miercuri 6 mai 2015, 13:51:57 +0300
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
**  Exercise 3.41: Write a prog to initialize a vector from an array of ints.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  Tre sa mai ma uit sa vad cum init cu un array un vector deja declarat..
**	Apparently nu se mai poate defini prin array dupa mom declararii...
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <iterator>

int main()
{
	std::cout << "\nLet's say we have an array of ints:" << std::endl;
	int arr[] {5,65,67978,6,654,23,5445,675,8426,4};
	for (auto abeg = std::begin(arr),aend = std::end(arr); abeg < aend;) {
		std::cout << ' ' << *abeg;
		abeg = std::next(abeg);
	}

	std::cout << "\n\nAnd an unitialized vector of ints:" << std::endl;
	std::vector<int> vi;
	if (vi.empty())
		std::cout << "It's empty, trust me ;-)" << std::endl;
	else {
		std::cout << "Seems like it is not empty..." << std::endl;
		for (auto x : vi)
			std::cout << ' ' << x;
	}

	std::cout << "\nWe can initialize it from the above array with any " \
			  << "number of elements we like,\nby using the syntax\n\t" \
			  << "std::vector<int> name (begin(array), end(array)" 		 \
			  << "\nwhere each arguments of begin and end is a pointer to" \
			  << "\nthe object that would be the begin/end limit." << std::endl;
	std::cout << "So that very same empty vector, now initialized with all" \
			  << " the elements \nof the array is..:" << std::endl;
	std::vector<int> vi (std::begin(arr), std::end(arr));
	for (auto x : vi)
		std::cout << ' ' << x;

	std::cout << '\n' << std::endl;

	return 0;
}