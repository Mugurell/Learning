/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 2 mai 2015, 17:27:11 +0300
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
**  Capitalize the first char of a string using an iterator.
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
**  Be very carefull at the dereferencing part - lines 53, 63, 65 ;-)
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <ctype.h>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	cout << "\nSay something\n\t";

	string saying;
	getline(cin, saying);
	auto another = saying.begin();

	if (saying.begin() != saying.end()) {	// make sure saying is not empty
		auto it = saying.begin();			// denotes the first character in s
		/* Now dereference the first char (this is the iterator!)
		** and change it's case.*/
		*it = toupper(*it);		
		another = it;			
	}

	for (auto word : saying) {
		cout << "\nThe first char said is " << word << '.' << endl;
		break;
	}
	cout << "\nThe second char said is " << saying[1] << '.' << endl;

	cout << "\nAn iterator to saying.begin() is " << *another << '.' << endl;

	cout << "\n An iterator to saying.end() is " << *saying.end() << '.' << endl;

	cout << "\nAnd the saying with the first char capitalized is:\n\t" \
		 << saying << '\n' << endl;

	return 0;
}