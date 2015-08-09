/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 5 mai 2015, 21:37:56 +0300
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
**  Exercise 3.36: Write a program to compare two arrays for equality. 
**	Write a similar program to compare two vectors.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  Apparently when comparing vectors first thing verified are the objects.
**	If they are all equal, then the nr of objects is compared.
**	When comparing arrays though, first the sizes of em are checked, and only
**	if both sizes are the same, then each individual element in the same exact
**	position is checked for equality.!!!
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <iterator>

int main()
{
	std::cout << "\nSo let's say we have 2 vectors of ints:" << std::endl;
	std::vector<int> v1 {1,2,3,4,5,6,7,8};
	std::vector<int> v2 {1,3,3,4,5};

	std::cout << "\tVector 1:" << std::endl;
	for (auto v1beg = v1.begin(), v1end = v1.end(); v1beg < v1end; v1beg++)
		std::cout << ' ' << *v1beg;
	std::cout << "\n\tVector 2:" << std::endl;
	for (auto x : v2)
		std::cout << ' ' << x;

	std::cout << "\n\nIf we compare them, we can easily see that" << std::endl;
	if (v1 > v2)
		std::cout << "\tFirst vector is bigger than the second\n" << std::endl;
	else if (v2 > v1)
		std::cout << "\tSecond vector is bigger than the first\n" << std::endl;
	else
		std::cout << "\tBoth vectors are actually equal\n" << std::endl;



	std::cout << "\n\nNow let's say we have 2 arrays to compare...:" << std::endl;
	int arr1[] {11,22,33,44,55,66,77,88};
	int arr2[] {11,22,999,44,55,66,77};

	std::cout << "\tstring 1:" << std::endl;
	for (auto a1beg = std::begin(arr1), a1end = std::end(arr1); a1beg < a1end;\
		a1beg = std::next(a1beg))
		std::cout << ' ' << *a1beg;
	std::cout << "\n\tString 2:" << std::endl;
	for (auto x : arr2)
		std::cout << ' ' << x;

	std::cout << "\n\nIf we compare them, we can easily see that" << std::endl;
	if (arr1 > arr2)
		std::cout << "\tFirst array is bigger than the second\n" << std::endl;
	else if (arr2 > arr1)
		std::cout << "\tSecond array is bigger than the first\n" << std::endl;
	else
		std::cout << "\tBoth arrays are actually equal\n" << std::endl;

	return 0;
}