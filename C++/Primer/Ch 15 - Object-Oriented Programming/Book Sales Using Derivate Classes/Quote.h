/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          27-Jul-15, 01:37 PM
 *  Last updated:     04 Aug 2015, 19:34:53:098 
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
 *  Exercise 15.3: Define your own versions of the Quote class and the
 *  print_total function.
 *  Exercise 15.11: Add a virtual debug function to your Quote class hierarchy
 *  that displays the data members of the respective classes.
 *  Exercise 15.26: Define the Quote and Bulk_quote copy-control members
 *  to do the same job as the synthesized versions. Give them and the other
 *  constructors print statements that identify which function is running. Write
 *  programs using these classes and predict what objects will be created and
 *  destroyed. Compare your predictions with the output and continue
 *  experimenting until your predictions are reliably correct.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  This is used to "model different kinds of pricing strategies".
 *  Quote, will be the base class of our hierarchy.
 *  A Quote object will represent undiscounted books.
 *  From Quote we will inherit other classes, to represent books that can be
 *  sold with a quantity discount.
 *
********************************************************************************
*******************************************************************************/


#ifndef BOOK_SALES_USING_DERIVATE_CLASSES_QUOTE_H
#define BOOK_SALES_USING_DERIVATE_CLASSES_QUOTE_H


#include <iostream>
#include <string>
#include <new>
#include <utility>      // std::move



// Will be used as a base function
class Quote {
public:
    // will use the in-class initializer to init price
    Quote() { std::cout << "\n**default constructor for Quote**\n"; };
    Quote(const std::string &book, double sales_price);

    Quote(const Quote &copyFromMe);
    Quote(Quote &&moveFromMe) noexcept;
    Quote& operator=(const Quote &copyFromMe);
    Quote& operator=(Quote &&moveFromMe) noexcept;

    // Virtual function to return a dynamically allocated copy of itself
    // These members use reference qualifiers (specifies if the calling this
    // pointer is a lvalue reference or a rvalue reference)
    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone()    &&   { return new Quote(std::move(*this)); }

    std::string isbn() const { return bookNo; }

    // Return the total sales price for the specified number of items.
    // Derived classes will override and apply different discount algorithms.
    virtual double net_price(std::size_t n) const { return n * price; }

    // Display the data members of all classes in the hierarchy.
    virtual void debug() const;

    // Base classes ordinarily should define a virtual destructor.
    // Virtual destructors are needed even if they do no work.
    // virtual ~Quote() = default;     // dynamic binding for the constructor
    virtual ~Quote() { std::cout << "\n**Quote destructed**\n"; }

private:
    std::string bookNo;

protected:
    // in-class initializer will be used by the default constructor of Quote
    double price = 9.3;
};



#endif //BOOK_SALES_USING_DERIVATE_CLASSES_QUOTE_H
