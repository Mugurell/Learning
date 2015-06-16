/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 11 iunie 2015, 22:36:08 +0300
**  Last updated:     vineri 12 iunie 2015, 11:52:16 +0300
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
**  Exercise 10.22: Rewrite the program to count words of size 6 or less using
**	functions in place of the lambdas
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None ---  
**
**  Notes:
**  ----
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <functional>		// bind(), ref(), cref()...
#include <algorithm>		// for_each()..

using std::placeholders::_1; using std::placeholders::_2;

bool isBiggerThan6(const std::string&, const std::string::size_type&);
void printBiggerThan6(const std::string&, const std::string::size_type&);

int main()
{
	std::cout << std::unitbuf;		// flush the buffer after every output.

	std::vector<std::string> sentence = {"the", "quick", "red", "fox", "jumps",
									"over", "the", "slow", "red", "turtle"};

	std::cout << "\nSo we have a nice little sentence stored in a vector:\n\t";
	std::for_each(sentence.cbegin(), sentence.cend(),
				[](std::string word) { std::cout << word << ' '; });

	std::cout << "\n\nNow let's see how many words with >=6 chars are in it.."
			  << "\n\t";

	std::cout << "......\n\nApparently there are "
			  << count_if(sentence.cbegin(), sentence.cend(),
			  			bind(isBiggerThan6, _1, 6))
			  << " words with >=6 chars:\n\t";

	std::for_each(sentence.cbegin(), sentence.cend(),
					bind(printBiggerThan6, _1, 6));

	std::cout << "\n\nCool, huh?\n" << std::endl;

	return 0;
}


bool
isBiggerThan6(const std::string &word, const std::string::size_type &sz)
{
	return word.size() >= sz;
}


void
printBiggerThan6(const std::string &word, const std::string::size_type &sz)
{
	if (word.size() >= sz) std::cout << word << ' ';
}