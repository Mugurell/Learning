#ifndef _SALES_DATA_
	#define _SALES_DATA_
	
	#include <string>
	#include <iostream>
	
	struct Sales_data {
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0;
		std::string isbn() const { return bookNo; }
		Sales_data& combine(const Sales_data&);
		double avg_price() const;
	};



#endif