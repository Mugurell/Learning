#ifndef _SALES_DATA_
	#define _SALES_DATA_
	
	#include <string>
	
	struct Sales_data {
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0;
		std::string& isbn() const { return bookNo; }
		Sales_data& combine(const Sales_data&);
	};

	Sales_data& Sales_data::combine(const Sales_data& new_trans) {
	//	bookNo += new_trans.bookNo;
		units_sold += new_trans.units_sold;
		return *this;
	}

#endif