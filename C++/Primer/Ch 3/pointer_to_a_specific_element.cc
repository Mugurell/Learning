/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 5 mai 2015, 19:35:56 +0300
**  Last updated:     mari 5 mai 2015, 19:47:53 +0300
						- Am introdus beg = std::next(beg);
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
**  --- This is a description of what the program does ---
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  !!!! Pentru a lua adresa unui element specific dintr-un array, trebuie sa
**	folosesti the address-of operator !!!!!!
**
*******************************************************************************
******************************************************************************/



#include <iostream>
#include <iterator>		// necesar pt std::begin(arr) si std::end(arr).

int main()
{
	int arr[] {34,5,2346,54,76,8,65790};
	//int *ptr1 = arr[2];		// asta da eroare
	int *ptr2 = &arr[2];

	std::cout << "\nSo we have an array - arr[] :" << std::endl;

	/*for (auto x : arr) {
		std::cout << "\tPosition " << count << " - " << x << std::endl;
		count++;
	}*/

	unsigned count {0};
	// puteam sa folosesc si auto beg = begin(arr), end = end(arr);
	for (int *beg = std::begin(arr), *end = std::end(arr); beg < end; count++){
		std::cout << "\tPosition " << count << " - " << *beg << std::endl;
		beg = std::next(beg);
	};


	std::cout << "\nNow, ptr1 = arr[2] is would give us an error" << std::endl;
	std::cout << "So ptr2 = &arr[2] is " << ptr2 << " - " << *ptr2 \
			  << std::endl;
	std::cout << "All while arr[2] is " << &arr[2] << " - " << arr[2] \
			  << '\n' << std::endl;

	return 0;
}