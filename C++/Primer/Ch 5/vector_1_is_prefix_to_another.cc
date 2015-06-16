/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          duminic 10 mai 2015, 22:29:50 +0300
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
**  Exercise 5.17: Given two vectors of ints, write a program to determine
**	whether one vector is a prefix of the other. For vectors of unequal
**	length, compare the number of elements of the smaller vector. For
**	example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5,
**	8, respectively your program should return true.

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
**  You can't use a switch condition with true bool argument!!!
**	The compiler will politely suggest using a if-else statement.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>

void clear_cin(void);

int main()
{
	std::cout << "\nThis prog will compare two int vectors to see if one \n" \
			  << "is the prefix of the other.\n" << std::endl;

	/*
	** Initialize both vectors with values entered by the op.
	*/
	std::cout << "That being said please write next the values of the " \
			  << "first vector\n\t";

	std::vector<int> v1, v2;
	int nr;

	while (std::cin >> nr)
		v1.push_back(nr);
	clear_cin();

	std::cout << "\nNow please enter the values for the other vector\n\t";
	while (std::cin >> nr)
		v2.push_back(nr);
	clear_cin();

	std::cout << std::endl << "Standby, testing....\n\t...\n" << std::endl;

	/*
	** Ensure the larger vector is the second one.
	*/
	std::vector<int> temp;
	if (v1.size() == v2.size()) {
		std::cout << "Error: Both vectors have the same size!\n" << std::endl;
		return 0;
	} else if (v1.size() > v2.size()) {
		temp = v1;
		v1 = v2;
		v2 = temp;
	} else {
		// the second vector is bigger than the first. Great!
	}

	/*
	** Now do the comparation
	*/
	bool is_prefix = false;
	// x1 and x2 are of std::vector<int>::iterator type ;-)
	for (auto x1 = v1.begin(), x2 = v2.begin(); x1 != v1.end(); x1++, x2++) {
		if (*x1 == *x2)
			is_prefix = true;
		else {
			is_prefix = false;
			break;
		}
	}

	/*
	** Print the result.
	*/
	std::cout << "Seems to me that the smaller vector:\n\t";
	for (int x1 : v1)
		std::cout << ' ' << x1;
	if (is_prefix) {
		std::cout << "\nreally is the prefix of this other one:\n\t";
		for (int x2 : v2)
			std::cout << ' ' << x2;
	} else {
		std::cout << "\nactually is not the prefix of the other one -\n\t";
		for (int x2 : v2)
			std::cout << ' ' << x2;
	}


	std::cout << '\n' << std::endl;
	return 0;
}

void clear_cin(void)
{
	std::cin.clear();
	while (std::cin.get() != '\n');
}