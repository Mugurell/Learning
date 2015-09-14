/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          27-Jul-15, 02:05 PM
 *  Last updated:     04 Aug 2015, 19:34:37:120 
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
 *  Implementation file for the Discount classes.
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

#include <iostream>
#include <utility>      // std::move

#include "Discounts.h"
#include "Quote.h"


/*
 * DiscQuote implementation
 */

DiscQuote::DiscQuote(const std::string &book, double prais,
                     std::size_t qty, double disc)
        : Quote(book, prais), quantity(qty), discount(disc)
{ std::cout << "\n**DiscQuote constructor that takes 4 arguments**\n"; }


DiscQuote::DiscQuote(const DiscQuote &copyFromMe)
        : Quote(copyFromMe),
          quantity(copyFromMe.quantity),
          discount(copyFromMe.discount)
{ std::cout << "\n**DiscQuote copy constructor used**\n"; }


DiscQuote::DiscQuote(DiscQuote &&moveFromMe) noexcept
        : Quote(std::move(moveFromMe)),
          quantity(std::move(moveFromMe.quantity)),
          discount(std::move(moveFromMe.discount))
{ std::cout << "\n**DiscQuote move constructor used**\n"; }


DiscQuote& DiscQuote::operator=(const DiscQuote &copyFromMe)
{
    if (this != &copyFromMe) {      // protect against self-assignment
        Quote::operator=(copyFromMe);
        quantity = copyFromMe.quantity;
        discount = copyFromMe.discount;
    }

    std::cout << "\n**DiscQuote copy-assignment operator used**\n";
    return *this;
}


DiscQuote& DiscQuote::operator=(DiscQuote &&moveFromMe) noexcept
{
    if (this != &moveFromMe) {
        Quote::operator=(std::move(moveFromMe));
        this->discount = std::move(moveFromMe.discount);
        this->price = std::move(moveFromMe.price);
    }

    // the moved-from object is in a state safe to call the destructor on

    std::cout << "\n**move-assignment operator used**\n";
    return *this;
}



/*
 * CBulkQuote implementation
 */

BulkQuote::BulkQuote(const std::string &book, double prais,
                     std::size_t qty, double disc)
        : DiscQuote(book, prais, qty, disc)
{ std::cout << "\n**BulkQuote constructor that takes 4 arguments**\n"; }


BulkQuote::BulkQuote(const BulkQuote &copyFromMe)
        : DiscQuote(copyFromMe)
{
    std::cout << "\n**BulkQuote copy constructor used**\n";
}


BulkQuote::BulkQuote(BulkQuote &&moveFromMe) noexcept
        : DiscQuote(std::move(moveFromMe))
{
    std::cout << "\n**BulkQuote move constructor used**\n";
}


BulkQuote& BulkQuote::operator=(const BulkQuote &copyFromMe)
{
    if (this != &copyFromMe) {
        DiscQuote::operator=(copyFromMe);
        // BulkQuote has no other members so our work is done here
    }

    std::cout << "\n**bulkQuote copy assignment operator used**\n";
    return *this;
}


BulkQuote& BulkQuote::operator=(BulkQuote &&moveFromMe) noexcept
{
    if (this != &moveFromMe) {
        DiscQuote::operator=(std::move(moveFromMe));
        // BulkQuote has no other members so our work is done here
    }

    std::cout << "\n**BulkQuote move assignment operator used**\n";
    return *this;
}


void BulkQuote::debug() const
{
    std::cout << "Minimum quantity is " << quantity
              << " for a discount of " << discount;
}


double BulkQuote::net_price(std::size_t bought) const
{
    return bought * price * (bought >= quantity ? 1 - discount : 1);
}


/////////////////// For ex 15_6 ///////////////////////////////////
double PermDiscount::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}


double LimitedDiscount::net_price(std::size_t bought) const
{
    if (bought <= max_qty)
        return bought * (1 - discount) * price;
    else
        return bought * price;
}


void PermDiscount::debug() const
{
    std::cout << "Price for this new edition (" << isbn() << ") - "  << price
              << "\nMinimum quantity to purchase : " << min_qty
              << ", for a discount of " << discount * 100 << "%.";
}


void LimitedDiscount::debug() const
{
    std::cout << "Price for the last printing (" << isbn() << ") - " << price
              << "\nMaximum quantity to purchase : " << max_qty
              << ", for a discount of " << discount * 100 << "%.";
}