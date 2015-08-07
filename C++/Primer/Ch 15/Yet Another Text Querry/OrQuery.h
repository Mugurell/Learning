/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          07-Aug-15, 02:55 PM
 *  Last updated:           ---
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
 *  Inherit the BinaryQuery definition of rep, but overrides the eval function.
 *
********************************************************************************
*******************************************************************************/


#include <memory>
#include <new>

#include "BinaryQuery.h"
#include "Query_base.h"
#include "Query.h"
#include "QueryResult.h"
#include "TextQuery.h"


#ifndef YET_ANOTHER_TEXT_QUERRY_ORQUERY_H
#define YET_ANOTHER_TEXT_QUERRY_ORQUERY_H



class OrQuery: public BinaryQuery {
    friend Query operator| (const Query &l, const Query &r);

    OrQuery(const Query &left, const Query right)
            : BinaryQuery(left, right, "|") { }

    // concrete class: inherits rep and defines the remaining pure virtual
    QueryResult eval(const TextQuery&) const;
};


inline Query operator| (const Query &lhs, const Query &rhs)
{
    // implicitly uses the Query constructor that takes a shared_ptr<Query_base>
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}


#endif //YET_ANOTHER_TEXT_QUERRY_ORQUERY_H
