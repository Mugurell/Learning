/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 9 mai 2015, 18:23:29 +0300
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
**  Tries to exemplify the important step of declaring the control variable
**	in a range for loop as a reference for to be able to modify the original
**	values in the original container.
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
**	- Variabila cu care treci prin container intr-un range for e de tipul
**	continut in respectivul container. (eg: int, string, char, etc.);
**  - Daca vrei sa modifici un obiect dintr-un container (si sa-l salvezi
**	modificat in acel container) intr-un range for atunci trebuie ca variabila
**	cu care treci prin container sa fie definita ca referinta !!!
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>

int main()
{
	// Declare and initialize a vector of ints.
	std::vector<int> numar;
	for (int i = 0 ; i <= 10; i++) numar.push_back(i);

	// Print it so we'll have proof.
	std::cout << "\nNumarul este:" << std::endl;
	for (int x : numar)
		std::cout << ' ' << x;

	/*
	** Modify the original elements and print them.
	** If you don't declare the auto variable as a reference, the modified
	** value won't be saved in the container !!!!
	*/
	std::cout << "\n\nAcum modificam valorile initiale." << std::endl;
	std::cout << "Daca am declarat iteratorul ca si referinta, modificarile" \
			  << "\n\tvor fi salvate in containerul initial." << std::endl;
	for (int &x : numar) {
		x *= x;
		std::cout << ' ' << x;
	}

	/*
	** Print again the container.
	** If in the above range for the auto var was declared as a reference, 
	** this will print modified values.
	** Otherwise it will print the original values, modifications weren't saved
	*/
	std::cout << "\n\nDupa primul range for numarul este:" << std::endl;
	for (std::vector<int>::iterator beg = numar.begin(), end = numar.end(); \
		beg != end; beg = std::next(beg))
		std::cout << ' ' << *beg;

	std::cout << '\n' << std::endl;
	return 0;
}