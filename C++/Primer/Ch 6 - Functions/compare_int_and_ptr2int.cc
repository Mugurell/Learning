/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 14 mai 2015, 16:38:53 +0300
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
**  Exercise 6.21: Write a function that takes an int and a pointer to an int
**	and returns the larger of the int value or the value to which the pointer
**	points. What type should you use for the pointer?
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
#include <string>

std::string compare(const int, const int *);

int main()
{
	std::cout << "\nEnter 2 numbers then: ";
	int n1, n2;
	
	if (std::cin >> n1 >> n2) {
		if (n1 == n2)
			std::cout << "\nUhm.. they are both equal.. :-|.\n" << std::endl;
		else {
			std::string result = compare(n1, &n2);
			std::cout << "\nOut of the 2 numbers entered I'd say the\n\t" \
					  << result << " is the bigger.\n" << std::endl;
		}
	}
	else
		std::cout << "\nYu no vant?\n" << std::endl;

	return 0;
}

std::string compare(const int n1, const int *n2)
{
	if (n1 > *n2)
		return "first";
	else
		return "second";
}

