/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          05-Aug-15, 05:11 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  This will hold the details of individual persons and what books & how
 *  many of them each person bought.
 *  My implementation.
 *  Seems like this was superseded by Primer's Basket class.
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
********************************************************************************
*******************************************************************************/



#ifndef BOOK_SALES_USING_DERIVATE_CLASSES_PERSON_H
#define BOOK_SALES_USING_DERIVATE_CLASSES_PERSON_H


#include <iostream>
#include <vector>
#include <string>
#include <memory>       // std::shared_ptr

#include "Quote.h"
#include "Discounts.h"
#include "Functions.h"


class Person {
    friend void Functions::print_total(const Person &person);
    friend void Functions::print_books(const Person &person);

public:
    Person(std::string name) : name_(name) { }

    void buy_book(std::string book_name, double price);
    void buy_book(const BulkQuote* book);
    void show_books();
    void print_total_price();

    ~Person();

private:
    std::string name_;
    std::vector<Quote*> books_;
    double total_price = 0.0;

    double compute_total_price();   // will be used by print_total_price
};



#endif //BOOK_SALES_USING_DERIVATE_CLASSES_PERSON_H
