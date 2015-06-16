/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 2 mai 2015, 22:33:32 +0300
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
**  Exercise 3.22: Revise the loop that printed the first paragraph in text to
**	instead change the elements in text that correspond to the first paragraph
**	to all uppercase. After you’ve updated text, print its contents.
**
**  Bugs:
**  - Must be rewritten. 
** 	At this stage: compile error: *it has no member begin(). Line 69.
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  --- You can write here the execution command & the expected result --- 
**
**  Notes:
**  --- Anything that stands out ---
**  --- Or needs to be treated with special attention ---
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <vector>

int main()
{
	/*
	** Let's say this is the original loop (I made it now...).
	*/
/*	std::vector<std::string> text {"ana", "are", "mere", "\n", \
								   "multe", "mere", "."};

	for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
		std::cout << ' ' << *it;

	std::cout << std::endl;
*/


	std::vector<std::string> text {"ana", "are", "mere", "\n", \
								   "multe", "mere", "."};

	/* 
	** text.cbegin() ne dadea un itinerator catre un const.
	** permitea doar sa il citesti, nu rw. Noua ne trebuie rw.
	*/
	auto it = text.begin();
	std::cout << "it e " << *it << std::endl;
	do {
		while (*it != "\n")
			auto it2 = *it.begin();
			std::cout << "it2 e " << *it2 << std::endl;
			if (*it2 >= 'a' && *it2 <= 'z')
				*it2 -= 'a' - 'A';
		std::cout << ' ' << *it; 
	} while(it != text.cend());


	return 0;
}