/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 20 mai 2015, 15:35:48 +0300
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
**  Exercise 7.2: Add the combine and isbn members to the Sales_data
**	class you wrote for the exercises in § 2.6.2 (p. 76).
**	Exercise 7.3: Revise your transaction-processing program from § 7.1.1 (p.
**	256) to use these members.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  ---
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include "Sales_data.hh"

int main()
{
	Sales_data total;
	if (std::cin >> total.bookNo) {
		total.units_sold++;
		Sales_data trans;
		while (std::cin >> trans.bookNo) {
			trans.units_sold = 1;
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				trans.units_sold = 1;
				std::cout << total.units_sold << "(else) x " << total.bookNo \
						  << std::endl;
				total = trans;
			}
		}	// end while
		std::cout << total.units_sold << "(if) x " << total.bookNo << std::endl;
	} else {
		std::cout << "Error: No valid input." << std::endl;
	}

	std::cout << "\n" << std::endl;
	return 0;
}