/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          06-Aug-15, 04:48 PM
 *  Last updated:     06 Aug 2015, 19:13:42:685 
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



#include "Basket.h"
#include "Functions.h"


double Basket::total_receipt() const
{
    double sum = 0.0;       // holds the running total

    // iter refers to the first element in a batch of elements with same ISBN
    // Advance iter to the next key - skip over all the elements that match the
    // current key by calling upper_bound() which returns an iterator to the
    // element just past the end of that batch.
    for (auto iter = items.cbegin();
              iter != items.cend();
              iter = items.upper_bound(*iter))
    {
        // We know that at leat one element with this key is in the basket.
        // Print the line item for this book.
        sum += Functions::print_total(**iter, items.count(*iter));
    }

    // Print the final overall total.
    std::cout << "\n\tTotal Sale: " << sum << std::endl;

    return sum;
}
