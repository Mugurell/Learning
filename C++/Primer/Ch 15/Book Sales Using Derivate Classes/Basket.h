/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          06-Aug-15, 04:48 PM
 *  Last updated:     06 Aug 2015, 19:13:33:263 
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Exercise 15.30: Write your own version of the Basket class and use it to
 *  compute prices for the same transactions as you used in the previous
 *  exercises.
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



#ifndef BOOK_SALES_USING_DERIVATE_CLASSES_BASKET_H
#define BOOK_SALES_USING_DERIVATE_CLASSES_BASKET_H


#include <memory>
#include <set>

#include "Quote.h"
#include "Discounts.h"

class Basket {
public:
    // will use the synthesized default constructor and copy-control members

    void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }

    // new versions of add_item() to avoid forcing the user to deal with
    // dynamic memory
    void add_item(const Quote &sale)       // copy the given object
        { items.insert(std::shared_ptr<Quote>(sale.clone())); }
    void add_item(Quote &&sale)            // move the given object
        { items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }

    // print the total price for each book and the overall total for all items
    // in the basket
    double total_receipt() const;

private:
    // function to compare shared_ptrs needed by the multiset member
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs)
    { return lhs->isbn() < rhs->isbn(); }

    // multiset to hold multiple Quotes, ordered by the compare member function
    // also intialize items to use the compare function - 0;
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};



#endif //BOOK_SALES_USING_DERIVATE_CLASSES_BASKET_H
