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
 *  ---
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


#include <new>      // new

#include "Person.h"
#include "Functions.h"



Person::~Person()
{
    for (auto &each : books_) {
        delete each;
        std::cout << "**Destroyed a book**\n";
    }

}
void Person::buy_book(std::string book_name, double price)
{
    Quote *book_bought = new Quote(book_name, price);
    books_.push_back(book_bought);         // add to the shopping basket
}


void Person::buy_book(const BulkQuote *book)
{
    BulkQuote *book_bought = new BulkQuote(*book);
    books_.push_back(book_bought);
}

void Person::show_books()
{
    Functions::print_books(*this);
}


double Person::compute_total_price()
{
    total_price = 0.0;
    for (const Quote *book : books_)
        total_price += book->net_price(1);

    return total_price;
}


void Person::print_total_price()
{
    std::cout << "\n\tGrand total: " << compute_total_price() << "\n\n";
}