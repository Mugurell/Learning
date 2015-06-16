/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 4 iunie 2015, 18:36:09 +0300
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
**  Exercise 9.28: Write a function that takes a forward_list<string> and
**	two additional string arguments. The function should find the first string
**	and insert the second immediately following the first. If the first string
**	is not found, then insert the second string at the end of the list.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None ---  
**
**  Notes:
**  Apparently std::forward_list doesnt know "--"" on it's iterators....
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <forward_list>
#include <string>


inline void clear_cin();
inline void print_list(const std::forward_list<std::string>&);
void search_insert_string(std::forward_list<std::string>&,
						const std::string&, const std::string&);

int main()
{
	std::forward_list<std::string> slist {"Ana", "are", "mere", "mari", "si",
											"zemoase"};

	std::cout << "\nSo I have a nice little strings fwlist:\n\t";
	print_list(slist);

	std::cout << "\n\nI can enter another word if you want.."
			  << "\nWhat word do you want to insert? : ";
	std::string list_word, to_be_entered;
	std::cin >> to_be_entered;
	clear_cin();
	std::cout << "\nAnd after what word do you want to be inserted?"
			  << "\nType word / blank for to be inserted at end: ";
	std::cin >> list_word;

	search_insert_string(slist, list_word, to_be_entered);

	std::cout << "\n\nCool!"
			  << "\nHere's the new strings list:\n\t";
	print_list(slist);

	std::cout << '\n' << std::endl;
	return 0;
}


inline void 
print_list(const std::forward_list<std::string> &slist)
{
	for (std::string word : slist)
		std::cout << word << ' ';
}


void
search_insert_string(std::forward_list<std::string> &list,
					const std::string &word_in_list,
					const std::string &to_be_entered)
{
	// std::forward_list<std::string>::iterator beg = list.begin();
	// bool word_found = false;
	// while (beg != list.end()) {
	// 	if (*beg == word_in_list) {
	// 		list.insert_after(beg, to_be_entered);
	// 		word_found = true;
	// 		break;
	// 	}
	// 	else
	// 		++beg;
	// }

	// if (!word_found)
	// 	list.insert_after(--(list.end()), to_be_entered);

	std::forward_list<std::string>::iterator prev = list.before_begin();
	for (auto curr = list.begin(); curr != list.end(); prev = curr++) 
		if (*curr == word_in_list) {
			list.insert_after(curr, to_be_entered);
			return;
		}

	list.insert_after(prev, to_be_entered);
}


inline void
clear_cin()
{
	std::cin.clear();
	while (std::cin.get() != '\n');
}