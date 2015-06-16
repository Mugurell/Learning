#ifndef SALES_DATA_HH
#define SALES_DATA_HH

/* All this is included in a 'header guard' !!!
*/

#include <string>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

#endif