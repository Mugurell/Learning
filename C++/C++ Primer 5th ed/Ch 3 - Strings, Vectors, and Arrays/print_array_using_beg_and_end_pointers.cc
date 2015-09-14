/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 5 mai 2015, 14:37:51 +0300
**  Last updated:     		---
**
**  Compilation:  g++ -std=gnu++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**	 (g++ 5.1)		  -Woverloaded-virtual -Winvalid-pch -Wcast-align
**					  -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**					  -Wmissing-format-attribute -Wmissing-include-dirs  
**					  -Wredundant-decls -Wswitch-default -Wswitch-enum  
**
**  Execution:    ./...
**
**  Description:
**  What the name said...
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
**  Although we can compute an off-the-end pointer, doing so is error-prone.
**	To make it easier and safer to use pointers, the new library - C++11 
**	includes two functions, named begin and end. These functions act like the 
**	similarly named container members. 
**	However, arrays are not class types, so these functions are not member
**	functions. Instead, they take an argument that is an array:
**		int ia[] = {0,1,2,3,4,5,6,7,8,9}; // ia is an array of ten ints
**		int *beg = begin(ia); // pointer to the first element in ia
**		int *last = end(ia); // pointer one past the last element in ia
**	begin returns a pointer to the first, and end returns a pointer one past
**	the last element in the given array: These functions are defined in the 
**	iterator header.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <iterator>

int main()
{
	int arr[] {3425,4,6,234,63,5467};	//define an array with 6 elements[0->5]

	int *beg = std::begin(arr);		// pointer to the first element in arr
	auto last = std::end(arr);		// pointer to the last element in arr

	while (beg < last)
		std::cout << ' ' << *beg++;

	std::cout << '\n' << std::endl;

	return 0;
}

/****** Deprecated by te new standard - C++ 11 ***************
	auto ptr2beg = arr;
	int *ptr2end = &arr[6];

	std::cout << '\n' << std::endl;
	while (ptr2beg < ptr2end)
		std::cout << ' ' << *ptr2beg++;
*************************************************************/