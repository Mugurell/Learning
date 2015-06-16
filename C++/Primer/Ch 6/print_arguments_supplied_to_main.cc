/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 14 mai 2015, 18:10:09 +0300
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
**  Exercise 6.25: Write a main function that takes two arguments.
**	Concatenate the supplied arguments and print the resulting string.
**	Exercise 6.26: Write a program that accepts the options presented in this
**	section. Print the values of the arguments passed to main.
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

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "\nNo arguments received!\n" << std::endl;
	else {
		std::cout << "\nI have received the following arguments (" << argc \
				  << ") :" << std::endl;
		for (int x = 0; x < argc; ++x)
			std::cout << '\t' << x << " : " << argv[x] << std::endl; 
	}
	std::cout << '\n' << std::endl;

	return 0; 
}