#include <iostream>
#include "Sales_item.hh"

int main()
{
	Sales_item item1, item2;

	std::cin >> item1 >> item2;

	/*
	** Check if item1 and item2 have the same isbn
	*/
	if (item1.isbn() == item2.isbn()) {
		std::cout << "The sum of\n\t" << item1 << "\nand\n\t" \
				  << item2 << "\nis..\n\t" << item1+item2 	  \
				  << std::endl;
		exit(0);
	} else {
		std::cerr << "Data must refer to the same ISBN" \
				  << std::endl;
		exit(-1);
	}
	return 0;
}