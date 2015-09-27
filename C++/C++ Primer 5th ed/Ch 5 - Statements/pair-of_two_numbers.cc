/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 9 mai 2015, 18:48:35 +0300
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
**  --- This is a description of what the program does ---
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
**  This exercise should exemplify the implementation of do-while.
**	Instead I want to show that if cin is required to store only a fixed number
**	of variables, then it is not needed 
**			std::cin.clear()
**			while(std::cin.get() != '\n');
**	like how I do when I'm using for ex. while (std::cin >> number) {..}
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>

int main()
{
	std::string rsp;

	do {
		std::cout << "\nPlease enter two values: ";
		int val1, val2;
		if (std::cin >> val1 >> val2)
			std::cout << "If-ul a dat true!" << std::endl;
		else
			std::perror("Heroare");

		std::cout << "\nThe sum of " << val1 << " and " << val2 << " is " \
				  << val1 + val2 << '.' << std::endl;

		std::cout << "\nMore? Enter yes or no: ";
		std::cin >> rsp;
	} while (!rsp.empty() && rsp[0] != 'n');

	std::cout << '\n' << std::endl;
	return 0;
}