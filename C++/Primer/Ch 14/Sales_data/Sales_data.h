/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          15 Jul 2015, 21:44:02:011
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
 *  Exercise 14.2: Write declarations for the overloaded input, output,
 *  addition, and compound-assignment operators for Sales_data.
 *  Exercise 14.9: Define an input operator for your Sales_data class.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  The friend functions of a class must be also declared outside the class
 *  if we want to make them callable on their own.
 *
*******************************************************************************
******************************************************************************/


#ifndef SALES_DATA_SALES_DATA_H
#define SALES_DATA_SALES_DATA_H



#include <iostream>
#include <string>


class Sales_data {
    // Declarations for input, output and addition, as per Ex 14.2
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:
    // Default constructor will initialize our class with this default values
    Sales_data() : Sales_data("", 0, 0.0f) { }

    // If the user sends some arguments they will be used to construct the class
    Sales_data(const std::string &s, unsigned n, double p)
            : bookNo(s), units_sold(n), revenue(p * n) { }
    Sales_data(const std::string &s)
            : Sales_data(s, 0, 0.0f) { }      // delegate the second constructor

    // The class can also be initialized from an istream&.
    // The user will type values for each of the class's members.
    Sales_data(std::istream &is) { is >> *this; }

    // compound assignment operator
    Sales_data& operator+=(const Sales_data &rhs);

    std::string isbn() const { return bookNo; }

private:
    double average_price() const;

    std::string bookNo;
    unsigned units_sold;
    double revenue;
};


inline double
Sales_data::average_price() const
{
    return units_sold ? revenue/units_sold : 0;
}


#endif //SALES_DATA_SALES_DATA_H
