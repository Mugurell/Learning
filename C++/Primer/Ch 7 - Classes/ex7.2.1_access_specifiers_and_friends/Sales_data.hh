/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 22 mai 2015, 15:15:13 +0300
**  Last updated:     vineri 22 mai 2015, 21:20:54 +0300
**
**  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**	 (g++ 5.1)		  -Woverloaded-virtual -Winvalid-pch -Wcast-align
**					  -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**					  -Wmissing-format-attribute -Wmissing-include-dirs  
**					  -Wredundant-decls -Wswitch-default -Wswitch-enum  
**
**  Execution:    ./...
**
**  Description:
**  --- This is a description of what the program does ---
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**   - A const member function that returns *this as a reference should have a
**	return type that is a reference to const.
**	- The calling member will be const when the function is not supposed to
**	modify it's initial elements!!!
**
*******************************************************************************
******************************************************************************/



#ifndef _SALES_DATA_
	#define _SALES_DATA_

	#include <iostream>
	#include <string>


	class Sales_data {
	public:
		Sales_data() = default;
		Sales_data(const std::string &s, unsigned n, double p) {
			bookNo = s; units_sold = n; revenue = p * n;
		}; 
		Sales_data(const std::string &s): bookNo(s) { }
		Sales_data(std::istream&);

		std::string isbn() const { return bookNo; }
		Sales_data& combine(const Sales_data&);

	private:
		//double avg_price() const;	

		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;

		friend Sales_data add(const Sales_data&, const Sales_data&);
		friend std::istream& read(std::istream&, Sales_data&);
		friend std::ostream& print(std::ostream&, const Sales_data&);
	};


	// member functions
	Sales_data&
	Sales_data::combine(const Sales_data &item){
		units_sold += item.units_sold;
		revenue += item.revenue;
		return *this;
	}

/*	inline double
	avg_price() const {
		if (units_sold)
			return revenue / units_sold;
		else
			return 0;
	}
*/

	// non-member functions
	// friend functions
	std::istream&
	read(std::istream &is, Sales_data &item) {
		double price;
		is >> item.bookNo >> item.units_sold >> price;
		item.revenue = price * item.units_sold;
		return is;
	}

	std::ostream&
	print(std::ostream &os, const Sales_data &item) {
		os << item.bookNo << ' ' << item.units_sold << ' ' \
		   << item.revenue << ' ';
		return os;
	}

	Sales_data
	add(const Sales_data &lhs, const Sales_data &rhs) {
		Sales_data sum = lhs;
		sum.combine(rhs);
		return sum;
	}



	// constructor definition
	Sales_data::Sales_data(std::istream &is) {
		read(is, *this);
	}


#endif
