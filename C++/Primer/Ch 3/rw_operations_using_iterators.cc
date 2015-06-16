/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 2 mai 2015, 21:57:06 +0300
**  Last updated:     		---
**
**  Compilation:  g++ -std=gnu++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**	 (g++ 5.1)		  -Woverloaded-virtual -Winvalid-pch -Wcast-align
**					  -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**					  -Wmissing-format-attribute -Wmissing-include-dirs  
**					  -Wredundant-decls -Wswitch-default -Wswitch-enum  
**
**  Execution:    ./...
**
**  Description:
**  Do some basic rw operations using iterators
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  Print the same vector twice: original numbers/new ones.
**
**  Notes:
**  - Note the reassignment in line 59, bc i was previously incremented
**	until i == numar.end();
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>

int main()
{
	std::vector<int> numar {1,2,3,4,5,6,7,8,9};
	auto i = numar.begin();

	std::cout << "So first I had a vector with " << numar.size() \
			  << " numbers:\n\t";
	for(auto nr : numar)
		std::cout << ' ' << nr;


	std::cout << "\n\nBut after some basic rw operations using iterators\n" \
			  << "the " << numar.size() << " numbers in the same vector are:" \
			  << "\n\t";

	while (i != numar.end()) {
		*i += *i;
		i++;
	}

	i = numar.begin();
	while (i != numar.end())
		std::cout << ' ' << *i++;

	std::cout << '\n' << std::endl;

	return 0;
}
