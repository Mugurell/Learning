/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 10 iunie 2015, 19:17:31 +0300
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
**	Exercise 10.16: Write your own version of the biggies function using
**	lambdas.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  will find & print 3 words with size() >= 5.
**
**  Notes:
**  An updated version of elim_dups. Uses more algorithm functions and lambdas.
**  Tangled. Now in cinemas. :-)))
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <algorithm>
#include <string>

void biggies (std::vector<std::string> &, std::vector<std::string>::size_type);

void elimDups(std::vector<std::string>&);	// put sentence in alphabetical order
											// and remove duplicates
void print(const std::vector<std::string>&);

std::string make_plural(std::vector<std::string>::difference_type,
						std::string, std::string);

int main()
{
	std::cout << std::unitbuf;		// flush the buffer after every output.

	std::vector<std::string> sentence = {"the", "quick", "red", "fox", "jumps",
									"over", "the", "slow", "red", "turtle"};

	std::cout << "\nSo we have a nice little sentence stored in a vector:\n\t";
	print(sentence);

	std::vector<std::string>::size_type sz = 5;
	std::cout << "\n\nLet's see how many words have more than "
			  << sz << " chars.." << std::endl;
// print only the words with size() >= sz.
	biggies(sentence, sz);

	std::cout << "\n\nCool, huh?\n" << std::endl;
	return 0;
}


void
biggies (std::vector<std::string> &sentence, 
		std::vector<std::string>::size_type sz)
{

// remove duplicates
	elimDups(sentence);

// sort sentence by size 
// but maintain alphabetical order for words of the same size
	std::stable_sort(sentence.begin(), sentence.end(),
					[](const std::string &a, const std::string &b)
						{return a.size() < b.size();} );

// get an iterator to the first element whose size() is >= sz
	auto wc = find_if(sentence.begin(), sentence.end(),
					[sz](const std::string &a) { return a.size() >= sz; });

// compute number of elements with size >= sz
	std::vector<std::string>::difference_type count = sentence.end() - wc;

	std::cout << count << ' ' << make_plural(count, "word", "s")
			  << " of lenght " << sz << " or longer:\n\t";

// print words of the given size or longer, each one followed by a space
	std::for_each(wc, sentence.end(),
				[](const std::string &s) { std::cout << s << ' '; });

}


void
elimDups(std::vector<std::string> &saying) 
{
// sort the sentence alphabetically.
// needed because std::unique() only recognise adjacent sentence!!!!!!
	std::sort(saying.begin(), saying.end());

// unique reorders the input range so that each word appears once in the
// front portion of the range 
// and returns an iterator one past the unique range.
	std::vector<std::string>::const_iterator first_double;
	first_double = std::unique(saying.begin(), saying.end());

// erase the doubles
	saying.erase(first_double, saying.end());
}


void
print(const std::vector<std::string>& saying)
{
	for (std::string word : saying)
		std::cout << word << ' ';
}


std::string
make_plural(std::vector<std::string>::difference_type sz,
			std::string word, std::string s)
{
	return (sz > 1)? word+=s : word;
}