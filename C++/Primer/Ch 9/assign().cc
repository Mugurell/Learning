/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 2 iunie 2015, 18:31:37 +0300
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
**  The call to assign replaces the elements in names with copies of the 
**	elements in the range denoted by the iterators. The arguments to assign
**	determine how many elements and what values the container will have.
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
**  Assign that lets us assign from a different but compatible type, or assign
**	from a subsequence of a container. The assign operation replaces all the
**	elements in the left-hand container with (copies of) the elements specified
**	by its arguments.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <list>


int main()
{
	std::cout << std::unitbuf;

	std::list<std::string> names;
	std::vector <const char *> oldstyle = {"Ana", "Banana", "Cristina", "Didina"};

	std::cout << "\nSo we have\n"
			  << "std::list<std::string> names:\n";
	for (const auto name : names)
		std::cout << '\t' << name << '\n';
	std::cout << "\nAnd\n"
			  << "vector <char *> oldstyle:\n";
	for (const auto name : oldstyle)
		std::cout << '\t' << name << '\n';

	std::cout << "\n\nAfter \"names.assign(oldstyle.begin(), oldstyle.end())\""
			  << "we'll have:\nnames:\n";
	//oldstyle = names;		// error: container types don't match
	names.assign(oldstyle.begin(), oldstyle.end());

	for (const auto name : names)
		std::cout << '\t' << name << '\n';
	std::cout << "\nAnd\n"
			  << "vector <char *> oldstyle:\n";
	for (const auto name : oldstyle)
		std::cout << '\t' << name << '\n';

	std::cout << '\n' << std::endl;

	return 0;
}
