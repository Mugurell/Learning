/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 3 iunie 2015, 16:38:10 +0300
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
**  This is a small practice exercise in which I will use the iterator returned
**	by insert() (C++11) in a loop to add elements to a list.
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
**  	The end result is what I would have obtained if I used push.front().
**	This is not an expensive operation as it has been used on a list.
**	If it were used on a vector however all the elements would have be moved
**	to make room for a new element at the front of the vector. V. expensive!
**		Before the loop, we initialize iter to 1st.begin(). The first call to 
**	insert takes the string we just read and puts it in front of the element
**	denoted by iter. The value returned by insert is an iterator referring to
**	this new element. We assign that iterator to iter and repeat the while,
**	reading another word. As long as there are words to insert, each trip
**	through the while inserts a new element ahead of iter and reassigns to iter
**	the location of the newly inserted element. That element is the (new) first
**	element. Thus, each iteration inserts an element ahead of the first element
**	in the list.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <list>


int main()
{
	std::cout << "\nLet's say we have an empty string list."
			  << "\nWill you help me, fill it with something?"
			  << "Break it dowmn my man:\n\t";

	std::list<std::string> list;
	std::list<std::string>::iterator it = list.begin();
	std::string word;
	while (std::cin >> word)
		it = list.insert(it, word);

	std::cout << "\nNice man!"
			  << "\nSo here's what I recorded:\n\t";

	for (const auto wordd : list)
		std::cout << wordd << ' ';

	std::cout << "\n\nMuahahahaha\n\tHa!\n" << std::endl;

	return 0;
}