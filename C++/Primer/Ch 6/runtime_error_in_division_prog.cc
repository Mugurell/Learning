/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 12 mai 2015, 22:27:50 +0300
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
**  Exercise 5.23: Write a program that reads two integers from the standard
**	input and prints the result of dividing the first number by the second.
**	Exercise 5.24: Revise your program to throw an exception if the second
**	number is zero. Test your program with a zero input to see what happens on
**	your system if you don’t catch an exception.
**	Exercise 5.25: Revise your program from the previous exercise to use a
**	try block to catch the exception. The catch clause should print a message
**	to the user and ask them to supply a new number and repeat the code inside
**	the try.
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

#include "runtime_error_in_division_prog.hh"
// prototipurile functiilor si alte headere sunt in ... .hh


int main()
{
	return five25();
}


int five23(void)
{
	std::cout << "\nPlease enter 2 integers to be divided: ";

	std::cin >> n1 >> n2;

	if (n1 >= n2)
		std::cout << n1 << " / " << n2 << " = " << n1/n2 << '\n' << std::endl;
	else
		std::cout << n2 << " / " << n1 << " = " << n2/n1 << '\n' << std::endl;

	return 0;
}


int five24(void)
{
	std::cout << "\nPlease enter 2 numbers to be divided: ";

	std::cin >> n1 >> n2;

	if (n1 == 0 || n2 == 0)
		// throw std::exception();
		throw std::runtime_error("No division possible with a null element!");
	else if (n1 >= n2)
		std::cout << n1 << " / " << n2 << " = " << n1/n2 << '\n' << std::endl;
	else
		std::cout << n2 << " / " << n1 << " = " << n2/n1 << '\n' << std::endl;

	return 0;
}


int five25(void)
{
	std::cout << "\nPlease enter 2 numbers to be divided: ";

	while (std::cin >> n1 >> n2) {
		try {
			if (n2 == 0)
				throw std::runtime_error("Divisor is 0."
										" No division possible.");
			else {
				if (n1 >= n2)
					std::cout << n1 << " / " << n2 << " = " \
							  << static_cast<double>(n1)/n2 << '\n' \
							  << std::endl;
				else
					std::cout << n2 << " / " << n1 << " = " \
							  << static_cast<double>(n2)/n1 << '\n' \
							  << std::endl;
			}
		} catch (std::runtime_error err) {
			std::cout << err.what() \
					  << "\nTry entering another >0 numbers?" \
					  << "\nEnter \"y\" or \"n\" : ";
			char ch;
			std::cin >> ch;
			if (!std::cin || ch == 'n') 
				break;		// break out of the while loop
			else {		// print this and examine the while loop again.
				std::cout << "Enter then 2 numbers > 0 : ";
				std::cin >> n1 >> n2;
			}
		}
	}
	return 0;
}