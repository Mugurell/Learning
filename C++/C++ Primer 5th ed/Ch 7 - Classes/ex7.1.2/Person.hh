/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 20 mai 2015, 16:25:17 +0300
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
**  Exercise 7.4: Write a class named Person that represents the name and
**	address of a person. Use a string to hold each of these elements.
**	Subsequent exercises will incrementally add features to this class.
**	Exercise 7.5: Provide operations in your Person class to return the name
**	and address. Should these functions be const? Explain your choice.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  Regarding ex 7.5 I don't think the member functions should be const because
**	maybe I wanna change the person's name exactly through this functions.
**	Daca declaram functiile ca si constante (std::string get_name() const {..})
**	aveam avantajul ca puteam sa le dau ca si argument si un nonconst si un
**	const, dar nu puteam sa mai modific prin ele rezultatul -lvalue.
**
*******************************************************************************
******************************************************************************/




#ifndef _PERSON_
	#define _PERSON_

	#include <iostream>
	#include <string>
	
	struct Person {
		std::string name {};
		std::string address {};
		std::string& getName() { return name; }
		std::string& getAddress() { return address; }
	};

/*	// nonmember functions
	std::istream& operator>>( std::istream&, const Person &pers);
	std::istream & read(std::istream &is, const Person &pers) {
		is >> pers.name;// >> pers.address;
		return is;
	}*/

	std::ostream & print(std::ostream &os, const Person &pers) {
		os << pers.name << ' ' << pers.address << std::endl;
		return os;
	}

#endif