/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          duminic 17 mai 2015, 20:11:21 +0300
**  Last updated:     luni 18 mai 2015, 13:40:12 +0300
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
**  Exercise 6.54: Write a declaration for a function that takes two int
**	parameters and returns an int, and declare a vector whose elements have
**	this function pointer type.
**	Exercise 6.55: Write four functions that add, subtract, multiply, and divide
**	two int values. Store pointers to these functions in your vector from
**	the previous exercise.
**	Exercise 6.56: Call each element in the vector and print their result.
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
#include <vector>


// Declare and define the 4 functions as inline
inline int add(const int n1, const int n2) { return n1 + n2; }
inline int substract(const int n1, const int n2) { return n1 - n2; }
inline int multiply(const int n1, const int n2) { return n1 * n2; }
inline int divide(const int n1, const int n2) { return n1 / n2; }
inline void to_upper(char &);

int main()
{
	// Declare a vector of functions which return an int and take two ints as
	// parameters and initialize it with them functions.
	std::vector<int (*) (const int, const int)> v_func {add, substract, \
														multiply, divide};

	std::cout << "\nSo this program will perform the basic math operations.\n"\
			  << "For this I need you to enter 2 numbers: ";

	int n1, n2;
	std::cin >> n1 >> n2;

	std::cout << "Now what do you want to do with 'em my man?\n" \
			  << "[A] - Add\n" \
			  << "[S] - Substract\n" \
			  << "[M] - Multiply\n" \
			  << "[D] - Divide\n\t\t? >> ";

	char response;
	std::cin >> response;
	to_upper(response);

	switch (response) {
		case 'A': 
			std::cout << "The result is " << v_func[0](n1, n2) << ".\n" \
					  << std::endl;
			break;
		case 'S':
			std::cout << "The result is " << v_func[1](n1, n2) << ".\n" \
					  << std::endl;
			break;
		case 'M':
			std::cout << "The result is " << v_func[2](n1, n2) << ".\n" \
					  << std::endl;
			break;
		case 'D':
			std::cout << "The result is " << v_func[3](n1, n2) << ".\n" \
					  << std::endl;
			break;
		default:
			std::cout << "\nError: Command not found." << '\n' << std::endl;
	}

	return 0;
}


inline void to_upper(char &char_ref)
{
	if (char_ref >= 'a' && char_ref <= 'z')
		char_ref -= 'a' - 'A';
}

