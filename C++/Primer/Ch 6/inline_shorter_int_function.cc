/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 16 mai 2015, 13:00:33 +0300
**  Last updated:     sâmbt 16 mai 2015, 13:18:24 +0300
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
**  Exercise 6.44: Rewrite the isShorter function from § 6.2.2 (p. 211) to be
**	inline.

**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**   - inline and constexpr functions normally are defined in headers !!! 
**	 - Unlike other functions, inline and constexpr functions may be defined
**	multiple times in the program.
**	 - constexpr have a single return and all the parameters and returns are 
**	literals !!! Also they are implicitly inline !!! Returns constants only
**	when the arguments are constants, otherwise returns plain types.
**
*******************************************************************************
******************************************************************************/


#include <iostream>

inline const std::string isShorter(const int, const int);
constexpr int isSmaller(const int, const int);

int main()
{
	std::cout << "\nEnter 2 numbers to test (with the help of an inline " \
			  << "function)\n which is smaller: ";
	int n1, n2;
	std::cin >> n1 >> n2;

	std::cout << "\nSo, according to my calculations (based on an inline " \
			  << "function),\n\t" << isShorter(n1, n2) << " is smaller.\n" \
			  << std::endl;
	std::cout << "P.S\n I can also use a constexpr function to tell you that" \
			  << "\n\t" << isSmaller(n1, n2) \
			  << " is the smaller number\n" << std::endl;

	return 0;
}


inline const std::string isShorter(const int n1, const int n2)
{
	return n1 <= n2 ? "First number" : "Second number";
}


constexpr int isSmaller(const int n1, const int n2)
{
	return n1 <= n2 ? n1 : n2;
}