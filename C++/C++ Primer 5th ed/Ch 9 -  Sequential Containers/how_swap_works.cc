/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 2 iunie 2015, 19:53:30 +0300
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
**  Shows the difference between swapping arrays vs other seq containers.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**
**  Notes:
**  1) for arrays to be swapped, they all have to have the same type and the
**	same number of elements!
**	2) when swapping elements of 'normal' containers the elements stay on the
**	same address, only the name of the containers are changing !
**		when swapping arrays, the elements are copied into the mem address of
**	the other array !!! 
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <array>
#include <vector>


int main()
{
	std::cout << std::unitbuf;

	std::array<int, 10> arr1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::array<int, 10> arr2 = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	auto *parr = &arr1[3];

	std::vector<int> vec1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> vec2 = {10, 11, 12, 13, 14};
	auto *pvec = &vec1[3];


/*
** Show the behaviour of swap on 'normal' containers:
*/
	std::cout << "\nSo we have a 2 vectors of ints:\n"
			  << "\tvec1: ";
	for(auto nr : vec1)
		std::cout << nr << ' ';

	std::cout << "\n\tand vec2: ";
	for(auto nr : vec2)
		std::cout << nr << ' ';

	std::cout << "\n\tand a pointer - pvec = vec1[3] :\n\t\t\t"
			  << pvec << " - " << *pvec << ".\n";

	// do the swap
	vec1.swap(vec2);
	std::cout << "\nIf we do a vec1.swap(vec2), we'll have:\n"
			  << "\tvec1: ";
	for(auto nr : vec1)
		std::cout << nr << ' ';

	std::cout << "\n\tand vec2: ";
	for(auto nr : vec2)
		std::cout << nr << ' ';

	std::cout << "\n\tand the pointer - pvec = vec1[3] :\n\t\t\t"
			  << pvec << " - " << *pvec << ".\n";

	std::string dashes (40, '-');
	std::cout << '\n' << dashes << std::endl;



/*
** Show the behaviour of swap on an stl array:
*/
	std::cout << "So we have a 2 arrays of ints:"
			  << "\n\tarr1: ";
	for(auto nr : arr1)
		std::cout << nr << ' ';

	std::cout << "\n\tand arr2: ";
	for(auto nr : arr2)
		std::cout << nr << ' ';

	std::cout << "\n\tand a pointer - parr = arr1[3] :\n\t\t\t"
			  << parr << " - " << *parr << ".\n";


	// do the swap
	arr1.swap(arr2);
	std::cout << "\nIf we do a arr1.swap(arr2), we'll have:"
			  << "\n\tarr1: ";
	for(auto nr : arr1)
		std::cout << nr << ' ';

	std::cout << "\n\tand arr2: ";
	for(auto nr : arr2)
		std::cout << nr << ' ';

	std::cout << "\n\tand the pointer - parr = arr1[3] :\n\t\t\t"
			  << parr << " - " << *parr << ".\n";


	std::cout << std::endl;
	return 0;
}