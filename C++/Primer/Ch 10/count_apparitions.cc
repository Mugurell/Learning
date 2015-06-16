/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          luni 8 iunie 2015, 21:33:30 +0300
**  Last updated:     luni 8 iunie 2015, 21:49:20 +0300
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
**  Exercise 10.1: The algorithm header defines a function named count that, 
**	like find, takes a pair of iterators and a value. count returns a count
**	of how often that value appears. Read a sequence of ints into a vector
**	and print the count of how many elements have a given value.
**	Exercise 10.2: Repeat the previous program, but read values into a list of
**	strings.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None ---  
**
**  Notes:
**  --- -
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <algorithm>
#include <vector>
#include <list>


unsigned read_into_vector(void);
unsigned read_into_list(void);

int main()
{
	std::cout << "\nQuick, give me a list of numbers:\n\t";
	unsigned count = read_into_list();

	std::cout << "\nYour searched value appeared " << count
			  << " times!!! \n" << std::endl;

	return 0;
}


unsigned
read_into_vector(void)
{
	std::vector<int> numbers;
	int nr;

	while (std::cin && std::cin >> nr)
		numbers.insert(numbers.cend(), nr);

	std::cin.clear();
	while(std::cin.get() != '\n');

	std::cout << "\nNow let's search for a value and see how many times"
			  << "was that repeated.."
			  << "\nWhat value should we search for?\n\t- ";
	std::cin >> nr;
	unsigned count = std::count(numbers.cbegin(), numbers.cend(), nr);

	return count;
}


unsigned
read_into_list(void)
{
	std::list<int> numbers;
	int nr;

	while (std::cin && std::cin >> nr)
		numbers.insert(numbers.cend(), nr);

	std::cin.clear();
	while(std::cin.get() != '\n');

	std::cout << "\nNow let's search for a value and see how many times"
			  << "was that repeated.."
			  << "\nWhat value should we search for?\n\t- ";
	std::cin >> nr;
	unsigned count = std::count(numbers.cbegin(), numbers.cend(), nr);

	return count;
}