/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 9 iunie 2015, 19:53:27 +0300
**  Last updated:     miercuri 10 iunie 2015, 17:15:05 +0300
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
**  Exercise 10.9: Implement your own version of elimDups. Test your program
**	by printing the vector after you read the input, after the call to unique,
**	and after the call to erase.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  used a lambda and not the is_shorter function as a parameter to stable_sort
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>


bool is_shorter(const std::string&, const std::string&);

int main()
{
	std::cout << std::unitbuf;		// flush the buffer after every output.

	std::vector<std::string> sentence = {"the", "quick", "red", "fox", "jumps",
									"over", "the", "slow", "red", "turtle"};

	std::cout << "\nSo we have a nice little sentence stored in a vector:\n\t";
	for (const std::string &word : sentence)
		std::cout << word << ' ';

	std::cout << "\n\nIf we're to eliminate all duplicate words, we'll remain "
			  << "with just:\n\t";

// sort the words alphabetically.
// needed because std::unique() only recognise adjacent words!!!!!!
	std::sort(sentence.begin(), sentence.end());

// unique reorders the input range so that each word appears once in the
// front portion of the range 
// and returns an iterator one past the unique range.
	std::vector<std::string>::const_iterator first_double
							= std::unique(sentence.begin(), sentence.end());

// erase uses a vector operation to remove the nonunique elements
	sentence.erase(first_double, sentence.cend());

//  A stable sort maintains the original order among equal elements.
// The predicate (is_shorter) will take care of sorting the strings
// based on their .size().
// The words of same lenght remain in alphabetical order.
	std::stable_sort(sentence.begin(), sentence.end(),
					[](const std::string &a, const std::string &b)
					   {return a.size() < b.size();});
	for (const std::string &word : sentence)
		std::cout << word << ' ';

	std::cout << '\n' << std::endl;
	return 0;
}


bool
is_shorter(const std::string &s1, const std::string &s2)
{
	return s1.size() < s2.size();
}