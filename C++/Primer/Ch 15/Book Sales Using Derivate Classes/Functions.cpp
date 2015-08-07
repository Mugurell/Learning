/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          27-Jul-15, 02:03 PM
 *  Last updated:     04 Aug 2015, 19:34:23:391 
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
 *  Implementation file for Functions.
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


#include "Functions.h"
#include "Person.h"


double
Functions::print_total(const Quote &item, size_t n)
{
    // depending on the type of the object bound to the item parameter
    // calls either Quote::net_price() or PermDiscount::net_price()
    double ret = item.net_price(n);

    std::cout << "ISBN: "<< item.isbn().substr(0, 10) // calls Quote::isbn()
              << " || # sold: " << n << " || total due: " << ret << std::endl;

    return ret;
}


void Functions::print_total(const Person &person)
{
    double total = 0.0;
    for (std::vector<Quote*>::const_iterator first = person.books_.cbegin(),
         end = person.books_.cend();
         first != end; ++first)
    {
        total += Functions::print_total(static_cast<const Quote &>(**first), 1);
    }

    std::cout << "\n\n\tTo the grand total of: " << total << std::endl;
}

void Functions::print_books(const Person &person)
{
    for (std::vector<Quote*>::const_iterator first = person.books_.cbegin(),
         end = person.books_.cend();
         first != end; ++first)
    {
        Functions::print_total(static_cast<const Quote &>(**first), 1);
    }
}