/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          07-Aug-15, 01:37 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Abstract base - will serve as the root of our query hierarchy.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  No public members because users/derived classes shouldn't use this directly.
 *  All use of Query_base will be through Query objects.
 *
********************************************************************************
*******************************************************************************/



#ifndef YET_ANOTHER_TEXT_QUERRY_QUERY_BASE_H
#define YET_ANOTHER_TEXT_QUERRY_QUERY_BASE_H



#include "QueryResult.h"


class Query_base {
    // members of Query will call the virtuals in Query_base
    friend class Query;

protected:
    using line_no = TextQuery::lineNo;     // used in the eval functions

    virtual ~Query_base() = default;

private:
    // returns the QueryResult that matches this Query
    virtual QueryResult eval(const TextQuery &) const = 0;

    // rep is a string representation of the query
    virtual std::string rep() const = 0;
};



#endif //YET_ANOTHER_TEXT_QUERRY_QUERY_BASE_H
