/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 20 mai 2015, 19:16:05 +0300
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
**  This is just a small test to see how a const member function operates
**	at runtime.
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
**  So for the assignment through my getName() and getAddress() to work they
**	need to return a std::string& and, of course, not be const member functions
**	Hence my assumption from 'Person.hh' Notes is correct !
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include "Person.hh"

int main()
{
	// Define a new variable for the struct Person
	Person a;
	a.name = "Ion";
	a.address = "Grivita";

	print(std::cout, a);

	std::cout << "Do you want to add another person?" << std::endl;
	Person b;
	std::cout << "Person 2's name is\n\t";
	std::cin >> b.getName();
	std::cout << "And lives in\n\t";
	std::cin >> b.getAddress();
	//std::cout << "Enter it's name, folowed by it's address." << std::endl;

	std::cout << "So now 2nd person is " << b.getName() << " which lives in " \
			  << b.getAddress() << ".\n" << std::endl; 

	return 0;
}