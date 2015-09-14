#ifndef _SALES_DATA_
#define _SALES_DATA_

#include <string>	

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

#endif //EX7_01_HEADER_FILE_H