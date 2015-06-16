/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 5 mai 2015, 13:02:29 +0300
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
**  Write a program to define an vector of ten ints. 
**	Give each element the same value as its position in the vector.
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
**	Rezolvarea e a lui moophie. Nu 0 prea inteleg..
**
*******************************************************************************
******************************************************************************/

#include <iostream>
#include <vector>

int main()
{
	int arr1 [10] {0,1,2,3,4,5,6,7,8,9};
	int arr2 [10];// {0,1,2,3,4,5,6,7,8,9};
	std::vector<int> vector (std::begin(arr1), std::begin(arr2));
	std::vector<int> vector2 (vector);

	std::cout << "begin(arr1) = " << std::begin(arr1) << " iar begin(arr2) = "\
			  << std::begin(arr2) << std::endl;
	std::cout << "\nvector 1 are " << vector.size() << " iar vector 2 are " \
			  << vector2.size() << std::endl;

	for (auto i : vector2)
		std::cout << ' ' << i;


	std::cout << '\n' << std::endl;

	return 0;
}