/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 3 iunie 2015, 17:26:19 +0300
**  Last updated:     miercuri 3 iunie 2015, 17:34:43 +0300
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
**  Exercise 9.18: Write a program to read a sequence of strings from the
**	standard input into a deque. Use iterators to write a loop to print the
**	elements in the deque.
**	Exercise 9.19: Rewrite the program from the previous exercise to use a
**	list. List the changes you needed to make.
**		I would just need to change deque with list. Same implementation,
**	same end result... Even with push_back() instead of insert().
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  	I used insert() and not push_back, as insert() is more exotic.
**	(At least for me, at this time...).
**		Used +1 in the ranged for because insert() would return me the position
**	at which it copied the object, and I should copy a new object in front of
**	that! (would ended up having the elements printed in reverse order...)
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <deque>
#include <string>


int main()
{
	std::cout << "\nThis is just a test for my memory :-D."
			  << "\nSo here's the plan:"
			  << "\nYou'll say something and when finished I'll show you what "
			  << "I remember.\n"  << std::endl; 

	std::deque<std::string> prop;
	auto end = prop.end();
	std::string word;

	while (std::cin >> word)
		end = (prop.insert(end, word))+1;

	std::cout << "\n\nLet's see..."
			  << "\nSo this is what I remember:\n" << std::endl;

	for (auto it = prop.cbegin(); it != prop.cend(); 
		std::cout << *it++ << ' ');

	std::cout << "\n\n\tYeah... I'm that good ! :-D \n" << std::endl;

	return 0;
}