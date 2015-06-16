/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 11 iunie 2015, 18:35:17 +0300
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
**  Exercise 10.21: Write a lambda that captures a local int variable and
**	decrements that variable until it reaches 0. Once the variable is 0
**	additional calls should no longer decrement the variable. The lambda should
**	return a bool that indicates whether the captured variable is 0.
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
**  Didn't really need to write the trailing return for the lambda.
**	The thing I wanted to test with it was that:
**		If you want a trailing return or mutable for a lambda,
**		you MUST write the (potentially empty) parameter list !!!!
**
*******************************************************************************
******************************************************************************/


#include <iostream>


int main()
{
	std::cout << "\nPlease enter a number, smaller than 20: ";
	short int nr;
	std::cin >> nr;
	short int copy = nr;

	auto lambada = [&] () -> bool { if (nr == 0) return true;
					  else if (nr < 0) {
					  	std::cout << "\nError: Too small!\n";
					  	return false;
					  }
					  else {
					  	while (nr > 0) --nr;;
					  	return false;
					  }
					};

	if (lambada())
		std::cout << "\n\n0.\nCool.\n\nBye!" << std::endl;
	else {
		std::cout << "\n\nSo we had " << copy
				  << "\nNow we have " << nr
				  << "\n\nHa-ha\n\tHa\nHa-ha" << std::endl;
	}

	return 0;
}