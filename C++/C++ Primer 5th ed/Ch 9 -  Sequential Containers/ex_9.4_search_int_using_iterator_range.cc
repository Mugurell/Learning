/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          luni 1 iunie 2015, 21:34:59 +0300
**  Last updated:     luni 1 iunie 2015, 22:11:41 +0300
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
**  Exercise 9.4: Write a function that takes a pair of iterators to a
**	vector<int> and an int value. Look for that value in the range and return
**	a bool indicating whether it was found.
**	Exercise 9.5: Rewrite the previous program to return an iterator to the
**	requested element. Note that the program must handle the case where the
**	element is not found.
**
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  Interesting behaviour of the const iterator...
**	 When we use auto with begin or end, the iterator type we get depends on the
**	container type. How we intend to use the iterator is irrelevant. The c versions let us
**	get a const_iterator regardless of the type of the container.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <iterator>


bool found_range(std::vector<int>::iterator&, std::vector<int>::const_iterator&, 
				const int);

int main()
{
	std::cout << std::unitbuf;	// flush the buffer after every output

	const std::vector<int> range;

	for (int x = 243; x != 343; x++)
		range.push_back(x);

	std::cout << "\nLet's say I have a vector of ints, with 100 values.\n"
	          << "(but I will not tell you the range... :P)\n\n"
	          << "Throw a number and I'll tell you if you've nailed it!\n\t";
	int nr;
	std::cin >> nr;

	auto beg = range.begin();

	// A.c. containerul e constant begin/end/rbegin/rend vor da un iterator
	// constant. (overloaded function!).;
	std::vector<int>::const_iterator end = range.cend();
	if (found_range(beg, end, nr)) {
		std::cout << "\n\tBravos my amigo!\nYou are goood!!\n"
				  << "You are oh so good!\nYou are the best!\n" << std::endl;

	// part added for to comply to ex 9.5.
		std::cout << "Indeed " << *beg << " is included in [" << *range.begin()
				  << " - " << *(end-1) << ").\n" << std::endl; 
	} else
		std::cout << "\n\tMmmm... \nNope. No. Nada. Nimic.\n\n" << std::endl;

	return 0;
}


bool 
found_range(std::vector<int>::iterator &beg,
			std::vector<int>::const_iterator &end, const int numar) {
	while (beg++ != end)
		if (*beg == numar) {
			end = beg;
			return true;
		}

	return false;
}