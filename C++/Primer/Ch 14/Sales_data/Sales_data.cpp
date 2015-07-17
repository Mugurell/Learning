/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          15 Jul 2015, 21:42:53:309
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Execution:    ./...
 *
 *  Description:
 *  Implementation file for the Sales_data class.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  ---
 *
*******************************************************************************
******************************************************************************/



#include "Sales_data.h"


Sales_data&
Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}


std::istream&
operator>>(std::istream &is, Sales_data &salesData)
{
    double price;     // we'll read into price before using it

    // read from the istream values for every member of our class
    is >> salesData.bookNo >> salesData.units_sold >> price;

    if (is) {   // if the read was successfull, no flags were set
                // we have complete the initialization of our Sales_data object
        salesData.revenue = price * salesData.units_sold;
    }
    else {      // if badbit or failbit were set
                // reset our object to an empty Sales_data as to protect from
                // the case in which we do read some input before the error
        salesData = Sales_data();
    }
    return is;
}


std::ostream&
operator<<(std::ostream &os, const Sales_data &salesData)
{
    os << salesData.isbn() << ' ' << salesData.units_sold << ' '
       << salesData.revenue << ' ' << salesData.average_price();

    return os;
}


Sales_data
operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;   // will use the synthesised copy-assignment operator
    return sum += rhs;
}