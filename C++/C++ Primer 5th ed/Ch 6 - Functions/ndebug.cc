/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          		---
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
**  Exercise 6.47: Revise the program you wrote in the exercises in § 6.3.2 (p.
**	228) that used recursion to print the contents of a vector to conditionally
**	print information about its execution. For example, you might print the 
**	sizeofnthe vector on each call. Compile and run the program with debugging
**	turned on and again with it turned off.
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



using Iter = std::vector<char>::iterator;

void print_vector(Iter beg, Iter end);

int main()
{
	std::cout << "\nSo we have a vector of chars, which we'll print using\n" \
			  << "a recursive function..\n" << std::endl;

	std::vector<char> prop {'\n', '\t', 'C', 'e', ' ', 'z', 'i', 'c', 'i', \
							' ', 'm', 'h', 'a', ' ', '?', '\n'};

	print_vector(prop.begin(), prop.end());

	std::cout << std::endl;
	return 0;
}

void print_vector(Iter beg, Iter end)
{
	if (beg < end) {
		#ifndef NDEBUG
		std::cerr << "Error: " << __FILE__ ": in function " << __func__ \
				  << " at line " << __LINE__ << "\n\tCompiled on "	 \
				  << __DATE__ << " at " << __TIME__ ":\n\tvector's size" \
				  << " was > 1.\n";
		#endif

		if (*beg == '\n')
			std::cout << "The char is newline" << std::endl;
		else if (*beg == '\t')
			std::cout << "The char is tab" << std::endl;
		else if (*beg == ' ')
			std::cout << "The char is space" << std::endl;

		else
			std::cout << "The char is " << *beg << std::endl;
		print_vector(std::next(beg), end);
	}
}