/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          22 Jul 2015, 17:13:37
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Execution:    ./...
 *
 *  Description:
 *  Usage of a simple class which defines a single operation: 
 *  the function-call operator. That operator takes an argument of type int and
 *  returns the argument’s absolute value.
 *  
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  ---
 *
*******************************************************************************
******************************************************************************/


#include <iostream>

struct AbsoluteInt {
	int operator() (int nr) { return nr < 0 ? -nr : nr; }
};

int main()
{
	std::cout << "\n\nProof of concept!\n"
			  << "\nPlease enter a negative number -> ";
	int nr;
	std::cin >> nr;
	AbsoluteInt test;

	std::cout << "The absolute value of " << nr << " is " << test(nr) << "\n\n";
	return 0;
}