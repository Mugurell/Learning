/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 2 mai 2015, 19:11:04 +0300
**  Last updated:     		---
**
**  Compilation:  g++ -std=gnu++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**	 (g++ 5.1)		  -Woverloaded-virtual -Winvalid-pch -Wcast-align
**					  -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**					  -Wmissing-format-attribute -Wmissing-include-dirs  
**					  -Wredundant-decls -Wswitch-default -Wswitch-enum  
**
**  Execution:    ./...
**
**  Description:
**  Change the first char of every word read to upper case using an iterator.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  The program works as intended. 
**
**  Notes:
**  Isn't is just a tad too cluttered? 
**
*******************************************************************************
******************************************************************************/

#include <iostream>
#include <string>

// using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	std::cout << "\nSay something\n\t";

	std::string saying;
	while (getline(std::cin, saying)) {
		if (saying.begin() != saying.end()) {
			auto first_char_in_prop = saying.begin();
			if (*first_char_in_prop >= 'a' && *first_char_in_prop <= 'z')
				*first_char_in_prop -= 'a' - 'A';
			for (auto ch = saying.begin(); ch < saying.end(); ++ch) {
				if (*ch == ' ' || *ch == '\t') {
					std::cout << *ch;
					if (*(ch+1) != ' ' || *(ch+1) != '\t') {
						if (*(ch+1) >= 'a' && *(ch+1) <= 'z') {
							*(ch+1) -= 'a' - 'A';
							std::cout << *(ch+1);
							ch += 1;
						}
					}
				} else
					std::cout << *ch;
			}
		}
		std::cout << std::endl << '\t';
	}

	std::cout << '\n' << std::endl;

	return 0;
}