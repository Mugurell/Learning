/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 3 iunie 2015, 21:32:22 +0300
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
**  Exercise 9.24: Write a program that fetches the first element in a vector
**	using at, the subscript operator, front, and begin. Test your program on
**	an empty vector.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  You'll have to compile once for each fetching try individually.
**	All will get a segmentation fault, except ap(), which will call terminate
**	after throwing an std::out of range.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec;

	std::cout << "\nSo we have a nice little empty vector:"
			  << "vec : ";
	if (vec.empty())
		std::cout << "<empty>\n\n";
	else
		std::cout << "Apparently not empty :-P\n\n";

	std::cout << "Let's see what happens when we try to fetch it's 1st element"
			  << '\n' << std::endl;

	std::cout //<< "vec[0] - "<< vec[0]
			 // << "\nvec.front() - " << vec.front()
			 // << "\n*vec.begin() - " << *vec.begin();
			  << "\nvec.at(0) - " << vec.at(0);
			  ;

	std::cout << '\n' << std::endl;

	return 0;
}