/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 12 iunie 2015, 13:16:36 +0300
**  Last updated:     vineri 12 iunie 2015, 13:54:06 +0300
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
**  Exercise 10.25: In the exercises for 10.3.2 you wrote a version of biggies
**	that uses partition. Rewrite that function to use check_size and bind.
**	So I'll rewrite partition_string.cc but instead on lambdas use bind.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  Print "quick jumps turtle". 
**
**  Notes:
**  	std::partition() will split the main argument in 2. In the left part it
**	will put the objects for which the condition is true, in the right part it
**	will put the objects for which the condition is false. 
**	It will return an iterator one past the last 'true' object. Easy peasy.
**		Apparently binded functions are not to be overloaded...
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <functional>		// bind(), ref(), cref()
#include <algorithm>		// partition(), for_each()

using std::placeholders::_1; using std::placeholders::_2;

bool isBiggerThan(const std::string&, const std::string::size_type&);
std::ostream& print(std::ostream&, const std::string&);
void prints(const std::vector<std::string>&);

int main()
{
	std::cout << std::unitbuf;		// flush the buffer after every output.

	std::vector<std::string> sentence = {"the", "quick", "red", "fox", "jumps",
									"over", "the", "slow", "red", "turtle"};
	std::vector<std::string>::size_type orig_size = sentence.size();

	std::cout << "\nSo we have a nice little sentence stored in a vector:\n\t";
	prints(sentence);

	std::cout << "\n\nWe'll now partition this vector so to focus on just"
			  << "\nwords that have >=5 characters:\n\t";


// Partition the strings vector no the condition size() >= 5
	std::vector<std::string>::const_iterator first_false;
	first_false = std::stable_partition(sentence.begin(), sentence.end(),
										bind(isBiggerThan, _1, 5));


// Can just resize the vector to contain only the 'true' elements.
	sentence.resize(std::distance(sentence.cbegin(), first_false));


// Print the vectors elements that comply to the condition (which are now all)
	std::for_each(sentence.cbegin(), sentence.cend(),
					bind(print, std::ref(std::cout), _1));


	std::cout << "\n\nPretty cool, huh\n" << std::endl;
	return 0;

}


bool
isBiggerThan(const std::string &word, const std::string::size_type &sz)
{
	return word.size() >= sz;
}


std::ostream&
print(std::ostream  &os, const std::string &word)
{
	std::cout << word << ' ';
	return os;
}


void
prints(const std::vector<std::string> &sentence)
{
	for (const std::string &word : sentence)
		std::cout << word << ' ';
}