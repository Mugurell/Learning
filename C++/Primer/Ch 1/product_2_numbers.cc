#include <iostream>

int main()
{
	long unsigned int v1, v2;

	std::cout << "Enter 2 numbers to find out their product:" << std::endl;
	std::cin >> v1 >> v2;
	std::cout << "The product of " << v1 << " and " << v2 \
			  << " is " << v1*v2 << '.' << std::endl;

	return 0;
}