#include <iostream>
#include "Sales_item.hh"

int main()
{
	Sales_item item1, item2;

	std::cin >> item1 >> item2;
	std::cout << "The sum of\n\t" << item1 << "\nand\n\t" << item2 \
			  << "\nis..\n\t" << item1+item2 << std::endl;

	return 0;
}