/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          		---
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
**  Exercise 6.36: Write the declaration for a function that returns a reference
**	to an array of ten strings, without using either a trailing return,
**	decltype, or a type alias.
**	Exercise 6.37: Write three additional declarations for the function in the
**	previous exercise. One should use a type alias, one should use a trailing
**	return, and the third should use decltype. Which form do you prefer and
**	why?
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
**  I would prefere the normal, basic way, or the triling return thingy!
**
*******************************************************************************
******************************************************************************/

// Easy peasy :-D

#include <iostream>
#include <string>

// the basic way
std::string (&func(void))[10];

// using an alias
typedef std::string arrT[10];
using arrT = std::string[10];

arrT & func(void);

// using trailing return
auto func(void) -> std::string(&)[10];

// using decltype (only if we know in advance what type of string can return)
decltype(type) * func(void);