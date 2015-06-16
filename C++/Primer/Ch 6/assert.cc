/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          luni 18 mai 2015, 15:24:15 +0300-
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
**  Show a basic implementation of assert and how NDEBUG can be defined at
**	at compile time.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
** 	The behavior of assert depends on the status of a preprocessor variable
**	named NDEBUG. If NDEBUG is defined, assert does nothing. By default, NDEBUG
**	is not defined, so, by default, assert performs a run-time check.
**	We can “turn off” debugging by providing a #define to define NDEBUG.
**	Alternatively, most compilers provide a command-line option that lets us
**	define preprocessor variables:
**		$ CC -D NDEBUG main.C 			# use /D with the Microsoft compiler
**	has the same effect as writing #define NDEBUG at the beginning of main.C.
**
*******************************************************************************
******************************************************************************/


#include <iostream>

//#define NDEBUG			// ifndef de mai jos verifica daca inainte de el !!! 
							// a fost sau nu declarat NDEBUG
	
#ifndef NDEBUG
	#include <cassert>
#endif
	

int main()
{
	std::cout << "\nPlease enter 2 numbers: ";

	int n1, n2;
	std::cin >> n1 >> n2;

	assert(n1 == n2);

	return 0;
}