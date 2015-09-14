/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 13 mai 2015, 21:59:28 +0300
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
**  Exercise 6.10: Using pointers, write a function to swap the values of two
**	ints. Test the function by calling it and printing the swapped values.
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

bool swap(int *, int *);
void print(int, int);

int main()
{
	std::cout << "\nEnter 2 numbers separated by spaces: " ;

	int n1, n2;
	std::cin >> n1 >> n2;

	std::cout << "\nCool!\nNow I'm gonna print your numbers:\n\t";
	print(n1, n2);

	std::cout << "\nNow I'm gonna swap their values using pointers" << std::endl;
	if (swap(&n1, &n2)) {
		std::cout << "\nSo now, trying to print the same exact numbers.." \
				  << " we get\n\t";
		print(n1, n2);
	} else
		std::cout << "\nSeems I couldn't do the swap... \n\tSorry!" << std::endl;

	std::cout << '\n' << std::endl;
	return 0;
}

bool swap(int *n1, int *n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;

	return true;
}

void print(int n1, int n2)
{
	std::cout << n1 << '\t' << n2 <<std::endl;
}