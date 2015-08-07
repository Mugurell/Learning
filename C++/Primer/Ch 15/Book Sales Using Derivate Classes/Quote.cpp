/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          27-Jul-15, 01:37 PM
 *  Last updated:     04 Aug 2015, 19:34:48:094 
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
 *  Implementation file for the Bulk class.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  Remember that we must specify noexcept both in the declaration in the
 *  class header and in the definition that appears outside of the class.
 *
********************************************************************************
*******************************************************************************/


#include <iostream>
#include <utility>      // std::move

#include "Quote.h"


Quote::Quote(const std::string &book, double sales_price)
        : bookNo(book), price(sales_price)
{ std::cout << "\n**Quote constructed from 2 arguments**\n"; }


Quote::Quote(const Quote &copyFromMe) : bookNo(copyFromMe.bookNo),
                                        price(copyFromMe.price)
{
    std::cout << "\n**Quote copy constructor**\n";
}


Quote::Quote(Quote &&moveFromMe) noexcept
        : bookNo(std::move(moveFromMe.bookNo)),
          price(std::move(moveFromMe.price))
{
    // the moved-from object is in a state safe to call the destructor on
    std::cout << "\n**Quote move constructor**\n";
}


Quote& Quote::operator=(const Quote &copyFromMe)
{
    if (this != &copyFromMe) {      // protect against self-assignment
        this->bookNo = copyFromMe.bookNo;
        this->price = copyFromMe.price;
    }

    std::cout << "\n**Quote copy-assignment operator**\n";
    return *this;
}


Quote& Quote::operator=(Quote &&moveFromMe) noexcept
{
    if (this != &moveFromMe) {      // check for self-assignment
        this->bookNo = std::move(moveFromMe.bookNo);
        this->price = std::move(moveFromMe.price);
    }

    // the moved-from object is in a state safe to call the destructor on

    std::cout << "\n**Quote move-assignment operator**\n";
    return *this;
}


void Quote::debug() const
{
    std::cout << "ISBN: " << bookNo << ", price - " << price;
}