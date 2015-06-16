#include <iostream>

int main()
{
	unsigned u = 10;
	int i = -42;

	std::cout << i + i << std::endl;
	std::cout << u + i << std::endl;

	unsigned u1 = 42, u2 = 10;
	std::cout << u1 - u2 << std::endl;
	std::cout << u2 - u1 <<std::endl;

	/*unsigned*/ u = 10;
	/*int*/ i = 10;
	std::cout << i - u << std::endl;
	std::cout << u - i << std::endl;

	int i2 = 42;
	std::cout << i2 - i << std::endl;
	std::cout << i - i2 << std::endl;

	return 0;
}