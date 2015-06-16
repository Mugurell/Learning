#include <iostream>

int main()
{
	int sum = 0;
	int value;

	/*
	** Read until EOF, calculating the running total of all valuea read
	*/
	while (std::cin >> value)
		sum += value;

	std::cout << "The sum of the numbers entered is "\
			  << sum << '.' << std::endl;

	return 0;
}