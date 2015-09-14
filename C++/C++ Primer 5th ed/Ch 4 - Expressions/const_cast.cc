/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 8 mai 2015, 14:57:54 +0300
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
**  Expected result:
**  --- You can write here the execution command & the expected result --- 
**
**  Notes:
**  Const_cast can only change constantness of a low level variable!
**
*******************************************************************************
******************************************************************************/


#include <iostream>

int main()
{
	int nr (42);
	const int *p2i = &nr;
	// *p2i = 783654;		- eroare la compilare pt, p2i fiind pointer 
	//							catre un int constant - nu poti modif int-ul.

	std::cout << "\nAvem nr - " << nr << " si *p2i = " << *p2i << std::endl;

	int *p2i2 = const_cast<int *> (p2i);

	*p2i2 = 99;

	std::cout << "Asta nu ar trebui sa mearga, *p2i nu ar trebui sa fie acum " \
			  << *p2i2 << std::endl;

	return 0;

}