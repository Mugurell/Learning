/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 28 mai 2015, 19:30:20 +0300
**  Last updated:     joi 28 mai 2015, 19:49:37 +0300
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
**  Exercise 8.1: Write a function that takes and returns an istream&. The
**	function should read the stream until it hits end-of-file. The function 
**	should print what it reads to the standard output. Reset the stream so that
**	it is valid before returning the stream.
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
**  --- Anything that stands out ---
**  --- Or needs to be treated with special attention ---
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>

std::istream& read(std::istream&, int&);

int main()
{
	// This manipulator tells the stream to do a flush after every subsequent
	// write. The nounitbuf manipulator restores the stream to use normal,
	// system-managed buffer flushing.
	std::cout << std::unitbuf;


	std::cout << "\n\tHello\n\nHow old are you? ";

	int age;
	std::istream &buffer = read(std::cin, age);
	std::cout << '\t' << age << " ... Hmmmm" << std::endl;
	std::cout << "And the state of the istream is " << buffer.rdstate()
			  << '\n' << std::endl;

	return 0;
}

std::istream&
read(std::istream &is, int &age) {
	is >> age;
	is.clear();
	return is;
}