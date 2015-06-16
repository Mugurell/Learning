/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 3 iunie 2015, 19:28:21 +0300
**  Last updated:     miercuri 3 iunie 2015, 21:16:26 +0300
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
**  The index must be “in range,” (i.e., greater than or equal to 0 and less
**	than the size of the container). It is up to the program to ensure that
**	the index is valid; the subscript operator does not check whether the index
**	is in range.
**	Using an out-of-range value for an index is a serious programming error,
**	but one that the compiler will not detect.
**	If we want to ensure that our index is valid, we can use the at member
**	instead which acts like the subscript operator, but if the index is
**	invalid at throws an out_of_range exception;
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  If the container I want to use a subscript on is has fewer elements than my
**	subscript, I hope that by using at() to subscript I'll catch the error it
**	throws and I'll correct this problem with the help of the operator. 
**
**  Notes:
**  This to me looks just beautiful. Not necessarily the way the program is
**	wrote, but the flow of execution with this try-throw-catch is unbelievable!
**	Added a new bool (first2) to be used a conditin for throwing the runtime
**	error. This way, this error will be thrown only once.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <stdexcept>


int main()
{
	std::vector<int> numbers {42341, 234, 95328};
	std::vector<int>::size_type it;

	std::cout << "\nLet's say I have a nice little ints vector.."
			  << "\nWhich of it's elements would you like to check?: ";
	std::cin >> it;


	// try to catch a possible out_of_range error:
	bool all_good = true;
	bool first2 = false;		// for simplifying the runtime_error catch
	while (all_good) {
		try {
			if (it == 2 && !first2) {
				first2 = true;
				throw std::runtime_error("Error: This is just a test! :P");
			}
			std::cout << "\n\nCool!"
					  << "\nSo at position " << it << " the vector has "
					  << numbers.at(it);
			break;
		} catch (std::out_of_range at) {
			std::cout << "\n" << at.what()
					  << "\n\nTry again? [Y] / [N]: ";
			char response;
			std::cin >> response;
			if (!std::cin || response == 'n' || response == 'N')
				all_good = false;
			else {
				std::cout << "Enter another position then: ";
				std::cin >> it;
				continue;
			}
		} catch (std::runtime_error re) {
			std::cout << '\n' << re.what() << std::endl;
			// std::cout << "But you must enter now another position..."
			// 		  << "\n\tSorry :-)"
			// 		  << "\nA new position to check? [Y] / [N]: ";
			// char response;
			// std::cin >> response;
			// if (!std::cin || response == 'n' || response == 'N')
			// 	all_good = false;
			// else {
			// 	std::cout << "Enter another position then: ";
			// 	std::cin >> it;
				continue;
			//}
		}
	}

	std::cout << '\n' << std::endl;
	return 0;
}