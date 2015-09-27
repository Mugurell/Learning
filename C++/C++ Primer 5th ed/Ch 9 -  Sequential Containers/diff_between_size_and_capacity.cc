/******************************************************************************
*******************************************************************************
**
**	Title:            Container size management functions.			
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 4 iunie 2015, 22:27:02 +0300
**  Last updated:     vineri 5 iunie 2015, 10:52:15 +0300
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
**
**  A small test to exemplify the diff between c.size() and capacity(), 
**	and between c.shrink_to_fit() and c.reserve().
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  - c.size() will give us the number of elements.
**	- c.capacity() will give us the maximum number of how many the container
**	can hold before more space must be allocated.
**
**  Notes:
**	- c.shrink_to_fit() will reduce the capacity to size().
**	The implementation allows for it to be ignored.
**	 - c.reserve() will alway get us >= current capacity && >= asked capacity.
**	As so, it can't be used to reduce the memory footprint.
**	Not to be confused with c.resize() which changes only the elements in the
**	container and not it's capacity.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::cin; using std::endl; using std::vector;

int main()
{
	vector<int> ivec;

	// size should be zero;
	// capacity is implementation defined.
	cout << "\nivec: size: " << ivec.size()
		 << "\n capacity: " << ivec.capacity() << endl;

	// give ivec 24 elements.
	for (vector<int>::size_type ix = 0; ix != 24; ++ix)
		ivec.push_back(ix);

	// size should be 24;
	// capacity will be >= 24 and is implementation defined.
	cout << "\nivec: size: " << ivec.size()
		 << "\n capacity: " << ivec.capacity() << endl;

	// add one more element to see how it affects capacity.
	ivec.push_back(12);
	cout << "\nivec: size: " << ivec.size()
		 << "\n capacity: " << ivec.capacity() << endl;

	// change the capacity by using shrink_to_fit.
	ivec.shrink_to_fit();
	cout << "\nivec: size: " << ivec.size()
		 << "\n capacity: " << ivec.capacity() << endl;

	// change the capacity by using reserve.
	ivec.reserve(100);
	cout << "\nivec: size: " << ivec.size()
		 << "\n capacity: " << ivec.capacity() << endl;

	// try to lower the memory footprint by using reserve.
	ivec.reserve(30);
	cout << "\nivec: size: " << ivec.size()
		 << "\n capacity: " << ivec.capacity() << endl;

	// increase it's capacity by resizing the vector
	ivec.resize(ivec.size()*5);	
	cout << "\nivec: size: " << ivec.size()
		 << "\n capacity: " << ivec.capacity() << endl;

	// interesting comparison resize() vs reserve()
	// seems like resize() will also double the previous capacity
	// when not enough space
	vector<std::string> svec;
	cout << "\nsvec: size: " << svec.size()
		 << "\n capacity: " << svec.capacity() << endl;
	svec.reserve(20);     // sets capacity to at least 1024
	cout << "\nsvec: size: " << svec.size()
 		  << "\n capacity: " << svec.capacity() << endl;
 	std::string word = "word";
	for (int x = 0; x <= 19; x++)
		svec.push_back(word);
	cout << "\nsvec: size: " << svec.size()
		 << "\n capacity: " << svec.capacity() << endl;
	svec.resize(svec.size()+svec.size()/2);
	cout << "\nsvec: size: " << svec.size()
		 << "\n capacity: " << svec.capacity() << endl;

	cout << '\n' << endl;
	return 0;
}