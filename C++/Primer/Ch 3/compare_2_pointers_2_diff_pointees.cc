/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 5 mai 2015, 21:55:21 +0300
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
**  I want to see which is the result of comparing 2 pointers of different
**	pointees. C++ Primer says the result is undefined..
**	Aren't pointers address in RAM? NUmbered addresses? Why can't compare?
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  Asadar nu e chiar undefined rezultatul.. 
**	Se compara adresa unde a fost stocat stringul respectiv...
**
*******************************************************************************
******************************************************************************/

#include <iostream>
#include <cstring>		// equivalent of C's string.h.

int main()
{
	const char s2[] = "A different string";
	const char s1[] = "A string";

	if (s1 < s2)
		std::cout << "\nS1 e mai mic pt ca " << &s1 << "\ne mai mic decat" \
				  << "\n\t\t   " << &s2 << std::endl;
	else if (s1 > s2)
		std::cout << "\nS1 e mai mare\n" << std::endl;
	else
		std::cout << "\nSunt egale\n" << std::endl;
}