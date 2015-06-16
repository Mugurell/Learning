//
// Created by Lingurar Petru-Mugurel on 27.05.2015.
//

#ifndef DELEGATING_CONSTRUCTORS_SALES_H
#define DELEGATING_CONSTRUCTORS_SALES_H

#include <iostream>
#include <string>


class Sales_data {
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);







    // Atat conteaza pt exercitiul asta.
    // Fii atent cum sunt chemati constructorii!
    // Hint: Cel care e chemat de un alt constr in itializeaza membrii si
    // executa primul it's body function. Apoi isi executa body functionul
    // si construtorul care a fost chemat prima data - in f de argumente.
public:
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s),units_sold(n),revenue(n*p)
    { std::cout << "1Sales_data(const std::string&, unsigned, double)" <<
                std::endl; }

    Sales_data() : Sales_data("", 0, 0.0f)
    { std::cout << "2Sales_data()" << std::endl; }

    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f)
    { std::cout << "3Sales_data(const std::string&)" << std::endl; }

    Sales_data(std::istream &is);
  //  { std::cout << "4Sales_data(istream &is)" << std::endl; }

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);













private:
    inline double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

inline
double Sales_data::avg_price() const
{
    return units_sold ? revenue/units_sold : 0;
}

// declarations for nonmember parts of the Sales_data interface.
std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

#endif   //7_5_DELEGATING_CONSTRUCTORS_SALES_H
