#include <iostream>

int & init(int *, int);

int main()
{
	std::cout << "\nThis little program will initialize our little int " \
			  << "array: " << std::endl;
	int ia[10];
	for (auto && nr : ia)
		std::cout << '\t' << nr << std::endl;

	std::cout << "\nUsing a function that returns a reference through which " \
			  << "will assign new values" << std::endl \
			  << "So out original array will now be.. :" << std::endl;

	for (int i = 0; i < 10 ; ++i) {
		init(ia, i) = i;		// init(ia, i) will return a reference
		std::cout << '\t' << ia[i] << std::endl;
	}

	std::cout << '\n' << std::endl;

	return 0;
}

int & init(int *array, int position) { return array[position]; }