#ifndef _SALES_DATA_
	#define _SALES_DATA_

	#include <iostream>
	#include <string>

	struct Sales_data {
		Sales_data() = default;
		Sales_data(const std::string &s): bookNo(s) { }
		Sales_data(const std::string &s, unsigned n, double p): \
					bookNo(s), units_sold(n), revenue(p) { }
		Sales_data(std::istream &is);	// will be defined outside

		std::string isbn() const { return bookNo; }
		/* Equivalent to
		std::string isbn() const { return this->bookNo }
			or
		std::string isbn() const { return (*this).bookno}
		*/
		Sales_data& combine(const Sales_data&);
		double avg_price() const;

		/* This initializations would be used by the
		** synthesized default constructor 
		** Because we defined a constructor this class will not have 
		** a default constructor unless we define it ourself
		** which we did - Sales_data() = default;	*/
		std::string bookNo;			// default initialization
		unsigned units_sold = 0;	// in-class initialization
		double revenue {0};			// in-class initialization
	};


	// member functions
	Sales_data&
	Sales_data::combine(const Sales_data &new_trans) {
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


	// non-member functions
	std::istream&
	read(std::istream &is, Sales_data &item) {
		double price = 0;
		is >> item.bookNo >> item.units_sold >> price;
		item.revenue = item.units_sold * price;
		return is;
	}

	std::ostream&
	print(std::ostream &os, Sales_data &item) {
		os << item.isbn() << ' ' << item.units_sold << ' ' \
		   << item.revenue << std::endl;
		return os;
	}

	Sales_data
	add(Sales_data lhs, const Sales_data rhs) {
		return lhs.combine(rhs);
	}


	// constructors definition
	// appears here bc it has to have read() allready declareds
	Sales_data::Sales_data(std::istream &is) {
		read(is, *this);
	}

#endif