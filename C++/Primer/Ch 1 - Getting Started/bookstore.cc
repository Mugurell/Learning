#include <iostream>
#include "Sales_item.hh"

int main()
{
	Sales_item total;

	if (std::cin >> total) {
		Sales_item trans;
		while (std::cin >> trans) {
			if (total.isbn() == trans.isbn())
				total += trans;
			else {
				std::cout << "Total is now " << total << std::endl;
				total = trans;
			}
		}
		std::cout << "Total's now " << total << std::endl;
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}