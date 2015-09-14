#include <iostream>

int main()
{
	int n1, n2;

	std::cout << "Please enter 2 numbers:" << std::endl;
	std::cin >> n1 >> n2;

	if (n1 > n2)
		while (n1 >= n2)
			std::cout << '\t' << n1-- << std::endl;
	else if (n1 < n2)
		while (n1 <= n2)
			std::cout << '\t' << n1++ << std::endl;
	else
		std::cout << "Cheeky ! \n\t :-P" << std::endl;

	return 0;
}