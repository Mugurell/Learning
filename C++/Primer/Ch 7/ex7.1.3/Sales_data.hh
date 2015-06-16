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

	// member functions
	Sales_data&
	Sales_data::combine(const Sales_data& new_trans) {
	//	bookNo += new_trans.bookNo;
		units_sold += new_trans.units_sold;
		revenue += new_trans.revenue;
		return *this;
	}

	double
	Sales_data::avg_price() const {
		if (units_sold)
			return revenue/units_sold;
		else 
			return 0;
	}

	// nonmember functions
	std::istream&
	read(std::istream &is, Sales_data &item) {
		double price = 0;
		is >> item.bookNo >> item.units_sold >> price;
		item.revenue = price * item.units_sold;
		return is;
	}

	std::ostream&
	print(std::ostream &os, const Sales_data &item) {
		os << item.isbn() << " " << item.units_sold << " " 
		   << item.revenue << " " << item.avg_price();
		return os;
	}

	Sales_data
	add(const Sales_data &lhs, const Sales_data &rhs) {
	    Sales_data sum = lhs;
	    sum.combine(rhs);
	    return sum;
	}

#endif