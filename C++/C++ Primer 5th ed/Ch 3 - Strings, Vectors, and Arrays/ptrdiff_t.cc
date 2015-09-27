/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 5 mai 2015, 18:30:59 +0300
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
**  --- This is a description of what the program does ---
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
**  The result of subtracting two pointers is a library type named ptrdiff_t.
**	Like size_t, the ptrdiff_t type is a machine-specific type and is defined
**	in the cstddef header. Because subtraction might yield a negative distance,
**	ptrdiff_t is a signed integral type.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <iterator>			// necesar pt std::begin(*ptr) si std::end(*ptr)
#include <cstddef>			// necesar pt ptrdiff_t

int main()
{
	int arr[] {6,56,76,87,879,89798,968};

	auto beg = std::begin(arr);
	int *end = std::end(arr);

	std::cout << "\n*end " << end << " - begin " << beg << " = " \
			  << end - beg << " or " << *(end-1) - *beg << '\n' << std::endl;

	/*
	** Now use a specific type to hold the difference between end & beg.
	*/
	auto diff = end - beg;		//diff e de tipul ptrdiff_t;
	std::cout << "ptrdiff says that arr -" << std::endl;
	unsigned count {0};
	for (auto x : arr) {
		count++;
		std::cout << '\t' << "Elm - " << count << " : " << x << std::endl;
	}
	std::cout << "has " << diff << " elements.\n" << std::endl;

	return 0;
}