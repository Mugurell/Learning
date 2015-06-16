#ifndef SALES_DATA_HH
#define SALES_DATA_HH 1

#include <string>

struct Books {
	std::string isbn = {0};
	unsigned nr = {0};
	double price = {0};
};

#endif