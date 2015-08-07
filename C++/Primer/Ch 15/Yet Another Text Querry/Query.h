/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          07-Aug-15, 01:45 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Provides the interface to (and hides) the Query_base inheritance hierarchy.
 *  Each Query object will hold a shared_ptr to corresponding Query_base object.
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



#ifndef YET_ANOTHER_TEXT_QUERRY_QUERY_H
#define YET_ANOTHER_TEXT_QUERRY_QUERY_H


#include <iostream>
#include <memory>

#include "WordQuery.h"
#include "TextQuery.h"

class Query {
    // this operators needs access to the shared_ptr constructor
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

    // display the associated Query
    friend std::ostream& operator<<(std::ostream&, const Query&);

public:
    // builds a new WordQuery
    Query(const std::string &s) : q(new WordQuery(s)) { }

    // interface functions: call the corresponding Query_base operations
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { return q->rep(); }

private:
    // we don’t intend general user code to define Query_base objects
    Query(std::shared_ptr<Query_base> query) : q(query) { }

    std::shared_ptr<Query_base> q;
};


inline std::ostream& operator<<(std::ostream &os, const Query &query)
{
    // Query::rep makes a virtual call through its Query_base pointer to rep()
    return os << query.rep();
}



#endif //YET_ANOTHER_TEXT_QUERRY_QUERY_H
