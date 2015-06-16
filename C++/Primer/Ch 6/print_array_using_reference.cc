/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 14 mai 2015, 17:41:39 +0300
**  Last updated:     		---
**
**  Compilation:  g++ -std=c++11 -Wall -Wextra -pedantic -Wshadow  
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
**  const int ia[10] is equal to const int *. 
**	const int ia[2134465] is equal to const int *. It all decay to a ptr 2 int!
**	So when received as a parameter, the function can't really know it's size.
**	Solution: Use a reference to an array !
**	Also, tried to see what will be the values of some unitialized variables
**	(removed the -Werror flag). Interesting things. Even more interesting when
**	I remove the declaration of d (and of course it's print).. -> f and ch
**	will be 'default initialized'? - they will have 0 and '' !!!
**
*******************************************************************************
******************************************************************************/


#include <iostream>

// void print(const int ia[10]);
void print(const int (&ria)[10]);

int main()
{
	const int ia[10] = {324,56,67,78};
	int x;
	float f;
	char ch;
	double d;
	std::cout << "\nx e " << x << " f e " << f << " ch e \"" << ch \
			  << '\"' << " d e " << d << std::endl;

	std::cout << "\nLet's say we have an array of ints:" << std::endl;
	print(ia);

	std::cout << "\nCool, huh?\n" << std::endl;
	return 0;
}

/* 
** This will print exactly 10 ints, because that's the condition in the for.
** Has nothing to do with the size of the received array!
void print(const int ia[10])
{
	for (size_t i = 0; i != 10; ++i)
		std::cout << ' ' << ia[i];
}
*/

/*
** Solutia asta o sa verifice la mom compilarii daca argumentul trimis catre
** functie - arrayul are intradevar atatea elemente cate au fost aratate in
** prototipul functiei. if not -> eroare.
** In felul asta, functia o sa printeze exact atatea elemente cate au fost
** aratate in function declaration in the calling function !!!
*/
void print(const int (&ria)[10])
{
	for (auto nr : ria) { std::cout << ' ' << nr; }
}