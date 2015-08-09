#include <iostream>
#include "Sales_item.hh"

int main()
{
	Sales_item item1, item2;
	int count = 0;

	while (std::cin >> item1) {
		count++;
		while (std::cin >> item2) {
			if (item1.isbn() == item2.isbn())
				count++;
			else {
				std::cout << item1.isbn() << " appeared " \
						  << count << " times " << std::endl;
				item1 = item2;
				count = 1;
			}
		}
		std::cout << "And "<< item1.isbn() << " appeared " \
				  << count << " times " << std::endl;
	}

	return 0;
}