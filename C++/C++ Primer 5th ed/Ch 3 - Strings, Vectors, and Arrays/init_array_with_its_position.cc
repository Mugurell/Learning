/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 5 mai 2015, 13:02:17 +0300
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
**  Exercise 3.31: Write a program to define an array of ten ints. Give each
**	element the same value as its position in the array.
**	Exercise 3.32: Copy the array you defined in the previous exercise into
**	another array.
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

int main()
{
	/*
	** Ex. 3.31: Initialize an array with it's position.
	*/
	constexpr size_t array_size {10};
	int array[array_size];

	for(size_t ix = 0; ix < array_size; ++ix) {
		array[ix] = ix;
		std::cout << "\nArray[" << ix << "] = " << array[ix];
	}
	std::cout << '\n' << std::endl;

	/*
	** Ex. 3.32: Copy the old array into a new one.
	*/
	constexpr size_t new_size {20};
	int new_array[new_size];

	for (auto x : array) {
		new_array[x] = array[x];
		++x;
	}

	std::cout << "That values, copied with a range for into another array" \
			  << "\nwould be..." << std::endl;
	for (auto x : new_array)
		std::cout << "new_array [" << x << "] = " << x << std::endl;
	std::cout << '\n' << std::endl;

	return 0;

}
