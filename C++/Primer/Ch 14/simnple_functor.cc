/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          21 Jul 2015, 18:13:37
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Execution:    ./...
 *
 *  Description:
 *  Exercise 14.34: Define a function-object class to perform an if-then-else
 *  operation: The call operator for this class should take three parameters. 
 *  It should test its first parameter and if that test succeeds, should return
 *  its second parameter; otherwise, it should return its third parameter.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  ---
 *
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>


class EasyCheck
{
	public:
		EasyCheck(std::ostream &o = std::cout) : os(o) { }

		void operator() (const int nr, const std::string a, 
						 const std::string b) { os << (nr < 99 ? a : b); }
	private:
		std::ostream &os;
};


int main()
{
	std::cout << "\n\nHow old are you? -> ";
	int age;
	std::cin >> age;

	EasyCheck checkAge;
	std::cout << "\n\n\t";
	checkAge(age, "In your prime!", "Still strong!");

	EasyCheck printToCerr(std::cerr);
	std::cout << "\n\n\t";
	printToCerr(100, "Cerr", "Printed to cerr");

	std::cout << "\n\n";
	return 0;
}