/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          27-Jul-15, 02:05 PM
 *  Last updated:     04 Aug 2015, 19:34:42:682
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
 *  Derived class from Quote.
 *  Exercise 15.5: Define your own version of the Bulk_quote class
 *  - (PermDiscount).
 *  Exercise 15.7: Define a class that implements a limited discount strategy,
 *  which applies a discount to books purchased up to a given limit.
 *  If the number of copies exceeds that limit, the normal price applies to
 *  those purchased beyond the limit.
 *  Exercise 15.15: Define your own versions of Disc_quote and Bulk_quote.
 *  Exercise 15.16: Rewrite the class representing a limited discount strategy,
 *  which you wrote for the exercises in § 15.2.2 (p. 601), to inherit from
 *  Disc_quote.
 *  Exercise 15.26: Define the Quote and Bulk_quote copy-control members
 *  to do the same job as the synthesized versions. Give them and the other
 *  constructors print statements that identify which function is running. Write
 *  programs using these classes and predict what objects will be created and
 *  destroyed. Compare your predictions with the output and continue
 *  experimenting until your predictions are reliably correct.
 *  Exercise 15.27: Redefine your Bulk_quote class to inherit its constructors.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  A class containing (or inheriting without overridding) a pure virtual
 *  function is an abstract base class.
 *  An abstract base class an defines interface for subsequent classes
 *  to override. We cannot (directly) create objects of a type that is
 *  an abstract base class.
 *  Because DiscQuote defines net_price as a pure virtual, we cannot define
 *  objects of type DiscQuote. We can define objects of classes that inherit
 *  from DiscQuote, so long as those classes override net_price.
 *
 *  About allowing polymorphic deletion through a base pointer:
 *  Any class that will be used as a base class (even an abstract one) and
 *  for which you want to allow user code to call delete must have it's
 *  destructor virtual. They are useful when you can delete an instance of a
 *  derived class through a pointer to base class:
 *  Ex:
 *      Base *pointer = new Derived();
 *      delete *pointer;    // this will call Base::~Base(). If it exists.
 *                          // When it is virtual, first ~Derived() will be
 *                          // called, and then ~Base().
 *  If you want to prevent the deletion of an instance through a base class
 *  pointer, you can make the base class destructor protected and non-virtual;
 *  by doing so, the compiler won't let you call delete on a base class pointer.
 *  See: http://www.gotw.ca/publications/mill18.htm
 *  &&   http://stackoverflow.com/questions/270917
 *  &&   http://stackoverflow.com/questions/24316700
 *  &&   http://stackoverflow.com/questions/677620
 *
 *  About inheriting base constructors:
 *  A class can "inherit" its base-class constructors by providing a using
 *  declaration that names its (direct!) base class. Works only for the
 *  direct base. The compiler will implicitly declare the corresp. constructors.
 *  Ex:
 *      using Base::Base;      // inherits Base constructors
 *  A class cannot inherit the default, copy, and move constructors.
 *  If the  derived class does not directly define these constructors, the
 *  compiler synthesizes them as usual.
 *
********************************************************************************
*******************************************************************************/


#ifndef BOOK_SALES_USING_DERIVATE_CLASSES_BULKQUOTE_H
#define BOOK_SALES_USING_DERIVATE_CLASSES_BULKQUOTE_H


#include <string>
#include <utility>      // std::pair, std::move
#include <new>

#include "Quote.h"



// Abstract class to hold the discount rate and quantity.
// Derived classes will implement pricing strategies using this data
class DiscQuote : public Quote {
public:
    DiscQuote() { std::cout << "\n**DiscQuote default constructor**\n"; }

    DiscQuote(const std::string &book,      // book ISBN / name
              double prais,                 // regular price
              std::size_t qty,          // quantity (min/max) to apply discount
              double disc);                 // discount

    DiscQuote(const DiscQuote &copyFromMe);
    DiscQuote(DiscQuote &&moveFromMe) noexcept;
    DiscQuote& operator=(const DiscQuote &copyFromMe);
    DiscQuote& operator=(DiscQuote &&moveFromMe) noexcept;

    // returns a pair holding the minimum (or maximum) quantity and the
    // discounted price
    std::pair<std::size_t, double> disc_policy() const
        { return {quantity, discount}; }

    // net_price() will be pure-virtual
    virtual double net_price(std::size_t bought) const override = 0;

    // Quote::~Quote() will b invoked automatically
    // Made this virtual to allow polymorphic deletion through a base pointer
    // See the Notes.
    virtual ~DiscQuote() { std::cout << "\n**DisqQuote destructed**\n"; }

protected:
    std::size_t quantity = 0;   // purchase size for the discount to apply
    double discount = 0;        // fractional discount to apply
};



// The discount kicks in when a exact number of copies of the same book are sold
// The discount is expressed as a fraction to use to reduce the normal price.
class BulkQuote : public DiscQuote {
public:
    BulkQuote() { std::cout << "\n**BulkQuote default constructor**\n"; }

    // Cool trick but I need to print something when this constructor is used
    // using DiscQuote::DiscQuote;     // inherits DiscQuote constructor
                                       // that takes 4 arguments ..or less

    BulkQuote(const std::string &book,      // book ISBN / name
              double prais,                 // regular price
              std::size_t qty,              // minimum quantity for discount
              double disc);                 // discount

    BulkQuote(const BulkQuote &copyFromMe);
    BulkQuote(BulkQuote &&moveFromMe) noexcept;
    BulkQuote& operator=(const BulkQuote &copyFromMe);
    BulkQuote& operator=(BulkQuote &&moveFromMe) noexcept;

    // Allocate a new object of it's own type to be used by Basket::add_item()
    BulkQuote* clone() const & override { return new BulkQuote(*this); }
    BulkQuote* clone() && override { return new BulkQuote(std::move(*this)); }

    // Overrides the base version to implement bulk purchase discount policy.
    virtual double net_price(std::size_t bought) const override;

    virtual void debug() const override;

    virtual ~BulkQuote() { std::cout << "\n**BulkQuote destructred**\n"; }
};



/////////////////// For ex 15_6 ///////////////////////////////////

class PermDiscount : public Quote {        // PermDiscount inherits from Quote
public:
    PermDiscount() = default;

    PermDiscount(const std::string &book, double praice,
             std::size_t qty, double disc)
            // delegate the Quote constructor to initialize it's own members
            : Quote(book, praice),
              min_qty(qty), discount(disc) { }   // then initialize it's own
    // overrides Base in order to implement the bulk purchase discount policy
    double net_price(std::size_t bought) const override;

    // overrides Base in order to print it's unique elements
    void debug() const override;

    virtual ~PermDiscount() = default;

private:
    std::size_t min_qty = 0;   // minimum purchase for to apply the dicount
    double discount = 0.0;      // fractional discount to apply
};


class LimitedDiscount : public Quote {
public:
    LimitedDiscount() = default;
    LimitedDiscount(const std::string &book, double praice,
                   size_t max_q, double disc)
            // delegate the Quote contructor to initialize it's members
            : Quote(book, praice),
            max_qty(max_q), discount(disc) { }   // init it's own

    // overrides Base in order to implement the discounts policy
    double net_price(std::size_t bought) const override;

    // overrides Base in order to print it's unique elements
    void debug() const override;

    virtual ~LimitedDiscount() = default;

private:
    std::size_t max_qty = 3;    // after this limit, return to normal price
    double discount = 0.0;      // fractional discount to apply

};


#endif //BOOK_SALES_USING_DERIVATE_CLASSES_BULKQUOTE_H
