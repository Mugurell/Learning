/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          07-Aug-15, 02:23 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  The ~ operator generates a NotQuery, which holds a Query, which it negates.
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



#ifndef YET_ANOTHER_TEXT_QUERRY_NOTQUERY_H
#define YET_ANOTHER_TEXT_QUERRY_NOTQUERY_H


#include <memory>
#include <new>

#include "Query_base.h"
#include "Query.h"
#include "QueryResult.h"
#include "TextQuery.h"


class NotQuery: public Query_base {
    friend Query operator~(const Query&);

    NotQuery(const Query &q) : query(q) { }

    // concrete class: NotQuery defines all inherited pure virtual functions
    std::string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery&) const;
    Query query;
};


inline Query operator~(const Query &operand)
{
    // implicitly uses the Query constructor that takes a shared_ptr<Query_base>
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}



#endif //YET_ANOTHER_TEXT_QUERRY_NOTQUERY_H
