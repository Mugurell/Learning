/******************************************************************************
*******************************************************************************
**
**  uthor:           Lingurar Petru-Mugurel
**  Written:          luni 8 iunie 2015, 22:28:24 +0300
**  Last updated:     mari 9 iunie 2015, 11:11:00 +0300
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
**  Exercise 10.3: Use accumulate to sum the elements in a vector<int>.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  --- 
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <numeric>		// needed for some special numeric algorithms
						// in this case - accumulate


int main()
{
	std::cout << "\nPlease enter some numbers:\n\t";
	int nr;
	std::vector<int> numbers;
	while (std::cin && std::cin >> nr)
		numbers.insert(numbers.cend(), nr);

	unsigned sum = std::accumulate(numbers.cbegin(), numbers.cend(), 10);

	std::cout << "\nAnd the sum is " << sum << '\n' << std::endl;

	return 0;
}
		