/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 10 iunie 2015, 19:33:06 +0300
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
**  Exercise 10.15: Write a lambda that captures an int from its enclosing
**	function and takes an int parameter. The lambda should return the sum of
**	the captured int and the int parameter.
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
	int n1 = 13, n2 = 24;
	auto sum = [n1] (int n20) {return n1 + n20;};
	std::cout << "\nSo we have two ints: " << n1 << " and " << n2 << '.'
			  << "\nAnd their sum is " << sum(n2)
			  << ".\n\nCool, rite?\n" << std::endl;

	return 0;
}