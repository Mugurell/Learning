#include <iostream>

int main()
{
	int ival = 42, *ptr = &ival;

	std::cout << *ptr << std::endl;

	*ptr = *ptr * *ptr;

	std::cout << *ptr << std::endl;

	void *ip = nullptr;


	return 0;
}