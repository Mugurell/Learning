#include <iostream>

int main()
{
	int x = 1, sum = 0;

	while (x <= 100)
		sum += x++;

	std::cout << "The sum of numbers 50 to 100 is " << sum \
			  << '.' << std::endl;

	return 0;
}