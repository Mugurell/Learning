/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 14 mai 2015, 19:38:03 +0300
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
**  Exercise 6.27: Write a function that takes an initializer_list<int>
**	and produces the sum of the elements in the list.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  We should use const reference as the loop control variable. because the
**	elements in an initializer_list are always const values, so we can't change
**	the value of an element in an initializer_list.
**	And to make sure that the reference will take any lvalue/rvalue, it's best
**	to use auto && which would bind to anything ! For more about auto&& see
**	http://stackoverflow.com/questions/13230480/what-does-auto-tell-us
**	http://stackoverflow.com/questions/9162808/what-does-auto-do
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <initializer_list>

int sum(std::initializer_list<int>);

int main()
{
	std::cout << "\nSo, we'll compute the sum of some numbers.." \
			  << "\nNothing groundbreaking you'd say..." \
			  << "\nBut the thing is that I'm gonna compute their sum" \
			  << "\nUsing an std::initializer_list<int> :-O" << std::endl;

/*
** Of course I can also store some user input and call the function based on this
	int n1, n2, n3;
	std::cin >> n1 >> n2 >> n3;
*/


	std::cout << "\nSo the sum of: " << std::endl;
	int total = sum({432,53,76,795,724,45});
	std::cout << "\n\tshould be.. " << total << ".\n" << std::endl;

	return 0;
}


int sum(std::initializer_list<int> numbers)
{
	int sum {0};
	int counter {0};
	// for (const int &nr : numbers) {		// see the second note
	for (auto &&nr: numbers) {				// nr will bind to anything !!!
		sum += nr;
		std::cout << "#" << counter++ << " - " << nr << std::endl;
	}

	return sum;
}