#include <iostream>

int main()
{
	struct Sales_data {
		std::string bookNo = "Joker";
		int v1 = 55, v2 = 14;
		double v3 = 4.423;
	};
	struct Sales_data s1;

	// s1.bookNo = {"Hello"};
	// s1.v1 = {999};

	std::cout << s1.bookNo << s1.v1 << s1.v2 << s1.v3 << std::endl;

	return 0;
}