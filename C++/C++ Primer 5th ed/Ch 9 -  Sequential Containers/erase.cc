/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 3 iunie 2015, 22:42:31 +0300
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
**  Exercise 9.26: Using the following definition of ia, copy ia into a vector
**	and into a list. Use the single-iterator form of erase to remove the
**	elements with odd values from your list and the even values from your
**	vector.
**			int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  --- 
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <list>
#include <vector>


int main()
{
	std::cout << std::unitbuf;		// flash the buffer after every output.

	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

	std::cout << "So we have a nice little int array - ia :\n\t";
	for (auto nr : ia)
		std::cout << nr << ' ';


	std::list<int> li (ia, std::end(ia));
	std::vector<int> vi (std::vector<int> (li.begin(), li.end()));

	for (auto it = li.begin(); it != li.end(); ) {
		if (*it % 2) it = li.erase(it);
		else it++;
	}

	for (auto it = vi.begin(); it != vi.end(); ) {
		if (!(*it % 2)) it = vi.erase(it);
		else it++;
	}


	std::cout << "\n\nAnd after a bit of work we splitted that in:"
			  << "\nA vector which has only the odds\n\t";
	for (auto nr : vi) std::cout << nr << ' ';

	std::cout << "\nA list which has all the evens\n\t";
	for (auto nr : li) std::cout << nr << ' ';


	std::cout << '\n' << std::endl;

	return 0;
}