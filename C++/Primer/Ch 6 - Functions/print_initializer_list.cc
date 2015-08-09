/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          luni 18 mai 2015, 17:03:49 +0300
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
**  --- This is a description of what the program does ---
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  If i initialize two new words at runtime and send this instead of the
**	default, they will not be auto-ccompleted by the others...
**	I only declare one default initializer_list, and replace it with a new one
**	constructed at runtime !!!
**	VS
**	I default initialize some function parameters and send arguments for fewer.
**
*******************************************************************************
******************************************************************************/#include <iostream>
#include <string>
#include <initializer_list>

void print_words(std::initializer_list<std::string> = {"\n\t", "Hello ", \
													   "World", "\n\n"});

int main()
{
/* I'm just gonna print a default message */

	std::cout << "\nIf you want you can insert some words, \n" \
			  << "Or I can continue with a default expression.." << std::endl;

	std::string w1, w2;
	std::cin >> w1 >> w2;
	print_words({w1, w2, , });

	// print_words();

	std::cout << '\n' << std::endl;
	return 0;
}

void print_words(std::initializer_list<std::string> prop)
{
	std::cout << "\nSizeof prop is " << prop.size() << '\n' << std::endl;
	for (auto && word : prop) {
		std::cout << word;
	}
}