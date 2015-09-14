/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          07-Aug-15, 02:47 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *  Implementation file for the AndQuery class
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



#include <algorithm>        // std::set_intersection
#include <iterator>         // std::inserter

#include "AndQuery.h"


// returns the intersection of its operands' result sets
QueryResult
AndQuery::eval(const TextQuery& text) const
{
    // virtual calls through the Query operands to get result sets
    // for the operands
    auto left = lhs.eval(text), right = rhs.eval(text);

    // set to hold the intersection of left and right
    auto ret_lines = std::make_shared < std::set < line_no >> ();

    // writes the intersection of two ranges to a destination iterator
    // destination iterator in this call adds elements to ret
    std::set_intersection(left.begin(), left.end(),
                          right.begin(), right.end(),
                          std::inserter(*ret_lines, ret_lines -> begin()));

    return QueryResult(rep(), ret_lines, left.get_file());
}