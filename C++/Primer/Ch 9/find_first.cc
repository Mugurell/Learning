/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 5 iunie 2015, 19:43:34 +0300
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
**  Exercise 9.47: Write a program that finds each numeric character and then
**	each alphabetic character in the string "ab2c3d7R4E6". Write two versions
**	of the program. The first should use find_first_of, and the second 
**	find_first_not_of.
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


int main()
{
	std::string test("ab2c3d7R4E6");
	std::string digits("123456789");
	std::string letter("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

	std::cout << "\nSo I've got a nice little string:\n\t";
	for (auto ch : test) std::cout << ch;
	std::cout << "\nNow let's see if there's any digits in there:"
			  << std::endl;

	// 1st use find_first_of()
	std::string::size_type pos = 0;
	while ((pos = test.find_first_of(digits, pos)) != std::string::npos) {
		// if found any digit:
		std::cout << "\tfound digit " << test[pos] << " at " << pos
				  << std::endl;
		++pos;	// otherwise - infinite loop
	}

	std::cout << "\nAnd any letters?:" << std::endl;
	pos = 0;
	while ((pos = test.find_first_of(letter, pos)) != std::string::npos) {
		std::cout << "\tfound letter " << test[pos] << " at " << pos
				  << std::endl;
		++pos;
	}



	// 2nd use find_first_not_of
	std::cout << "\n\nReset!\nOne more time!\n"
			  << "\nSo let's see them digits:" << std::endl;
	pos = 0;
	while ((pos = test.find_first_not_of(letter, pos)) != std::string::npos) {
		std::cout << "\tat position " << pos << " found " << test[pos]
				  << std::endl;
		++pos;
	}

	std::cout << "\nAnd now maybe some letter?:" << std::endl;
	pos = 0;
	while ((pos = test.find_first_not_of(digits, pos)) != std::string::npos) {
		std::cout << "\tat position " << pos << " found " << test[pos]
				  << std::endl;
		++pos;
	}

	std::cout << "\n\nCool, rite?\n" << std::endl;

	return 0;
}