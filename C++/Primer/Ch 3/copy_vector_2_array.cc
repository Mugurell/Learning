/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 6 mai 2015, 12:25:03 +0300
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
**  Exercise 3.42: Write a program to copy a vector of ints into an array of
**	ints.
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
**  --- Anything that stands out ---
**  --- Or needs to be treated with special attention ---
**
*******************************************************************************
******************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>		// necesar pt std::begin/end/next(arr).

int main()
{
	std::cout << "\nSo let's say we have an vector of ints:\n" << std::endl;
	std::vector<int> vi {423,534,6,8790789,765,6,54,6,67,87,5897};
	for (auto vbeg = vi.begin(), vend = vi.end(); vbeg != vend; vbeg++)
		std::cout << ' ' << *vbeg;

	std::cout << "\n\nNow let's say we also have an empty array of ints:\n";
	int arr[11] {0};
	for (auto x : arr)
		std::cout << ' ' << x;

	std::cout << "\n\nBut if we copy the elements from the vector to the array," \
			  << "\nthe array should now be...\n";
	for (int *abeg = std::begin(arr), *aend = std::end(arr); abeg != aend;) {
		*abeg  = vi[abeg - std::begin(arr)];
		std::cout << ' ' << *abeg;
		abeg = std::next(abeg);
	}

	std::cout << "\n\nGreat!\n" << std::endl;
	return 0;
}