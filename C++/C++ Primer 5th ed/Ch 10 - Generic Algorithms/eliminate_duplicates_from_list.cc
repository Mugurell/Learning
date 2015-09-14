/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          luni 15 iunie 2015, 21:45:45 +0300
**  Last updated:     		---
**
**  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**                    -Wmissing-format-attribute -Wmissing-include-dirs  
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
**
**  Execution:    ./...
**
**  Description:
**  Exercise 10.42: Reimplement the program that eliminated duplicate words
**	that we wrote in § 10.2.3 (p. 383) to use a list instead of a vector.

**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  Remember that list and fe_list have their own (faster) algorithms:
**	sort, merge, remove, reverse, unique.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>


int main()
{
	std::ostream_iterator<std::string> print(std::cout, " ");

	std::list<std::string> lint = {"the", "quick", "red", "fox", "jumps",
									"over", "the", "slow", "red", "turtle"};

	std::cout << "\nSo we have a nice little list of strings:\n\t";
	std::copy(lint.cbegin(), lint.cend(), print);

	std::cout << "\n\nLet's find the duplicate words using algorithms..";

	lint.sort();
	lint.unique();

	std::cout << "\n\n...\nSo we have..\n\t";
	std::copy(lint.cbegin(), lint.cend(), print);

	std::cout << "\n\nPretty cool, huh?\n" << std::endl;
	return 0;
}