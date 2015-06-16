/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 2 mai 2015, 20:04:56 +0300
**  Last updated:     sâmbt 2 mai 2015, 21:19:14 +0300
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
**  A simple test to see to what does the iterator refers to.
**
**  Bugs:
**	--- None anymore ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  Because s1 is default initialized, this will be printed -nothing-.
**
**  Notes:
**  -	*(i).empty only works bc "the object to which the iterator denotes"
**	has a class type - it's a vector of strings.
** 	When tried with string s1(10) I would get:
**  " check_empty_w_iterator.cc:47:11: error: request for member ‘empty’ in 
**	‘i.__gnu_cxx::__normal_iterator<_Iterator, _Container>::operator*<char*, 
**	std::basic_string<char> >()’, which is of non-class type ‘char’ "
** -	*(i).empty can be replaced with i->empty - which does the same thing:
**	dereferences i and then attempts to get the member empty from it.
**	(remember that the object to which i denotes is a class (a strucutre)).
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> s1 (10);

	auto i = s1.cbegin();

	if (i->empty())
		std::cout << "\nThe first element is empty -" << *i << ".\n" \
				  << std::endl; 
	else
		std::cout << "\nThe first element is not empty, it is - " << *i \
				  << ".\n" << std::endl;

	return 0;
}