/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 2 iunie 2015, 17:00:57 +0300
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
**  A simple program to test how can I copy a range from a container into
**	another container using iterators.
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
**  If the scope is to copy all elements from the container to another, we can
**	directly copy the container -" cont2(cont1) "". Thing is the containers and
**	the objects contained have to have the same type.
**	If the scope is to copy just a range of elements from a container to 
**	another, the containers can be of different types, and the objects
**	contained don't have to be of the same type if they can be implicitly
**	converted.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <deque>


int main()
{
	std::vector<std::string> vnames {"Ana", "Banana", "Crina", "Drina", "Elena",
									"Drina", "Eugenia", "Felicia", "Gina"};

	std::cout << "Let's say I have a vector of strings" << std::endl;
	for (const auto name : vnames)
		std::cout << '\t' << name << '\n';

	std::cout << "\nWill I be able to directly copy all the elements in the\n"
			  << "string vector to the string deque - deque(vector)? "
			  << "\n\tNo. To directly copy all the elements of a container"
			  << " into another\nthe container and the objects contained "
			  << "must have exactly the same type!\n" << std::endl;

	std::cout << "But will I be able to copy all or a range of elements from "
			  << "the vector\nusing a pair of iterators?\n\t"
			  << "Yes, as a matter of fact even all the elements of the string"
			  << " vector\ncan be copied into the string deque!\n"
			  << "\n\tThis are elements in the string deque after initializing"
			  << " it\nwith the begin & end iterators of the string vector: ";

	std::deque<std::string> dnames(vnames.begin(), vnames.end());
	for (const auto name : dnames)
		std::cout << "\n\t" << name;

	std::cout << "\n\nCool, right?!?\n"
			  << "Remember to remember it!\n" << std::endl;

	return 0;				  	
}
