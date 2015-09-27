/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          luni 4 mai 2015, 17:11:57 +0300
**  Last updated:     		---
**
**  Compilation:  g++ -std=gnu++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**	 (g++ 5.1)		  -Woverloaded-virtual -Winvalid-pch -Wcast-align
**					  -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**					  -Wmissing-format-attribute -Wmissing-include-dirs  
**					  -Wredundant-decls -Wswitch-default -Wswitch-enum  
**
**  Execution:    ./...
**
**  Description:
**  Print the sum of adjancet or extremes numbers in a vector
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
#include <vector>

using std::cin; using std::cout; using std::endl; using std::vector;

int main()
{
	cout << "Please enter some numbers, separated by spaces:" << endl;

	vector<int> numar;
	int nr_buff;
	while (cin >> nr_buff)
		numar.push_back(nr_buff);

	/*
	** Verifici daca bula a introdus ceva. Poti vedea daca
	** numar.begin() == numar.end() - caz in care nr e empty, sau..:
	*/
	if (numar.empty()) {
		cout << "You must introduce at least 1 number!" << endl;
		return -1;
	} else if (numar.size() == 1) {
		cout << *numar.begin() << " has no adjacent elements." << endl;
		return -1;
	}

	cout << "Now what do you want to do with em?:" << endl;
	cout << "\tOption A : Print the sum of the adjacent numbers." << endl;
	cout << "\tOption B : Print the sum of the extremes." << endl;
	cout << "\t   Please enter your choice: ";

	char response;
	cin.clear();
	while (cin.get() != '\n');
	cin >> response;
	if (response >= 'a' && response <= 'z')
		response -= 'a' - 'A';

	switch (response) {
		case 'A': 
			cout << "\nThe sums of adjacent numbers are:";
			for (auto it = numar.begin(); it+1 != numar.end(); ++it)
				cout << ' ' << *it + *(it+1);
			break;
		case 'B':
			cout << "The sum of the extrmes are:";
			for (auto beg = numar.begin(), end = numar.end()-1; \
				beg <= end; ++beg, --end)
				cout << ' ' << *beg + *end;
			break;
		default:
			cout << "\nTough choice, I understand.. :-|" << endl;
			break; 
	}

	cout << '\n' << endl;

	return 0;
}