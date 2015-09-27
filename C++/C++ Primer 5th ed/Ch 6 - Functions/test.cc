//
// typedef alias pt un array de 10 int
//


#include <iostream>

int main()
{
	//typedef int arrT[10]; // arrT is a synonym for the type array of ten ints

	typedef int arrT[10];

	arrT geo;

	std::cout << "arrt is " << geo.size() << std::endl;

}