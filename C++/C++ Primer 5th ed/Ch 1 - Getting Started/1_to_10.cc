#include <iostream>

int main()
{
	int x = 1, sum = 0;

	do {
		sum += x++;
	} while (x <= 10);

	std::cout << "Sum of numbers 1 to 10 is " << sum << '.' << std::endl;

	return 0;

