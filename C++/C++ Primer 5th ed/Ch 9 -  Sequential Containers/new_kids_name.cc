/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 5 iunie 2015, 17:50:16 +0300
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
**  Exercise 9.45: Write a funtion that takes a string representing a name
**	and two other strings representing a prefix, such as “Mr.” or “Ms.” and a
**	suffix, such as “Jr.” or “III”. Using iterators and the insert and append
**	functions, generate and return a new string with the suffix and prefix
**	added to the given name.
**	Exercise 9.46: Rewrite the previous exercise using a position and length to
**	manage the strings. This time use only the insert function.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None ---  
**
**  Notes:
**  --- 
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>

std::string generate_baby1(const std::string &name, const std::string &prefix, 
							const std::string &suffix);
std::string generate_baby2(const std::string &name, const std::string &prefix, 
							const std::string &suffix);

int main()
{
	const std::string name = {"Joshua"};
	const std::string prefix = {"Mr"};
	const std::string suffix = {"III"};

	std::cout << "\nI've just generated a new child.. (in reality a name..):"
			  << "\n\t" << generate_baby2(name, prefix, suffix);

	std::cout << '\n' << std::endl;
	return 0;
}

 
std::string
generate_baby1(const std::string &name, const std::string &prefix, 
				const std::string &suffix)
{
	std::string new_name = name;
	new_name.insert(new_name.begin(), prefix.begin(), prefix.end());
	new_name.append(suffix.begin(), suffix.end());

	return new_name;
}


std::string
generate_baby2(const std::string &name, const std::string &prefix, 
				const std::string &suffix)
{
	std::string new_name(name);
	new_name.insert(0, prefix);
	new_name.insert(new_name.size(), suffix);

	return new_name;
}