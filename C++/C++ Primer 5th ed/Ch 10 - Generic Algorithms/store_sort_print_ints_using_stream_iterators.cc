/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 13 iunie 2015, 20:02:13 +0300
**  Last updated:     sâmbt 13 iunie 2015, 21:12:24 +0300
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
**  Exercise 10.30: Use stream iterators, sort, and copy to read a sequence
**	of integers from the standard input, sort them, and then write them back to
**	the standard output.
**	Exercise 10.31: Update the program from the previous exercise so that it
**	prints only the unique elements. Your program should use unqiue_copy.
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
#include <vector>
#include <algorithm>
#include <iterator>


void thirty(void);
void thirty_one(void);

int main()
{
	std::cout << "\nType some numbers, I'll sort them out for ya:\n\t";

	thirty_one();

	std::cout << "\n\nPretty cool, huh?\n" << std::endl;
	return 0;
}

void
thirty(void)
{
	std::istream_iterator<int> input_nr(std::cin), eof;
	std::ostream_iterator<int> output(std::cout, " ");

	std::vector<int> vint(input_nr, eof);

	std::cout << "\n\nHere they come:\n\t";

	std::stable_sort(vint.begin(), vint.end());
	std::for_each(vint.cbegin(), vint.cend(), 
				[&output](const int &nr) { output = nr; });
}

void
thirty_one(void)
{
	std::istream_iterator<int> input_nr(std::cin), eof;

	std::vector<int> vint(input_nr, eof);

	std::cout << "\n\nHere they come:\n\t";

	std::stable_sort(vint.begin(), vint.end());

	std::unique_copy(vint.cbegin(), vint.cend(), 
					std::ostream_iterator<int>(std::cout, " "));
}