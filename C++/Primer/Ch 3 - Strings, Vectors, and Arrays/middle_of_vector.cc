#include <iostream>
#include <vector>

int main()
{
	std::vector<int> numar{1,2,3,4,888,6,7,8,9, 34567};

	auto beg = numar.cbegin(),  end = numar.cend();
	auto mid =beg + (end - beg)/2; 	//(end-beg)/2 imi da un long int

	std::cout << "So we have a vector of ints..\n\t";
	for (auto nr : numar)
		std::cout << ' ' << nr;
	std::cout << std::endl;

	std::cout << "The middle of which is " << *mid << std::endl;
}