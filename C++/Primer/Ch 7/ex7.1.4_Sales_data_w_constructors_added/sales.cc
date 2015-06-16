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
**  Exercise 7.11: Add constructors to your Sales_data class and write a
**	program to use each of the constructors.
**	Exercise 7.12: Move the definition of the Sales_data constructor that
**	takes an istream into the body of the Sales_data class.
**	Exercise 7.13: Rewrite the program from page 255 to use the istream
**	constructor.
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
#include "Sales_data.hh"

int main()
{
	Sales_data total;
	if (read(std::cin, total)) {
		Sales_data trans;
		while (read(std::cin, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(std::cout, total);
				total = trans;
			}
		}
		print(std::cout, total);
	} else {
		std::cerr << "Error: No valid input data!\n" << std::endl;
		return -1;
	}
	
	return 0;
}
