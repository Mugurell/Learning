#include <iostream>
#include <string>
#include "Sales_data.hh"

int main()
{
	Sales_data total;
	if (read(std::cin, total)) {
		Sales_data trans;
		while (read(std::cin, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(std::cout, total) << std::endl;
				total = trans;
			}
		}
		print(std::cout, total) << std::endl;
	} else {
		std::cerr << "Error: No valid input!\n" << std::endl;
		return -1;
	}

	std::cout << std::endl;
	return 0;
}