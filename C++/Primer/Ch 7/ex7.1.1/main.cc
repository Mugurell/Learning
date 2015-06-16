/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 19 mai 2015, 21:07:30 +0300
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
**  Exercise 7.1: Write a version of the transaction-processing program from §
**	1.6 (p. 24) using the Sales_data class you defined for the exercises in §
**	2.6.1 (p. 72).
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**
**  Notes:
**  --- 
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#ifndef _SALES_DATA_
	#include "Sales_data.hh"
#endif

int main()
{
	Sales_data total;
	if (std::cin >> total.bookNo) {
		total.units_sold++;
		Sales_data trans;
		while (std::cin >> trans.bookNo) {
			trans.units_sold++;
			if (total.bookNo == trans.bookNo) {
				total.units_sold++;
			} else {
				trans.units_sold = 1;
				std::cout << total.units_sold << " x " << total.bookNo \
						  << std::endl;
				total = trans;
			}
		}
		std::cout << total.units_sold << " x " << total.units_sold << std::endl;
	} else {
		std::cerr << "\nNo data?\n" << std::endl;
	}

	return 0;
}