/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          07-Aug-15, 02:15 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  A WordQuery looks for a given string. It is the only operation that actually
 *  performs a query on the given TextQuery object.
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



#ifndef YET_ANOTHER_TEXT_QUERRY_WORDQUERY_H
#define YET_ANOTHER_TEXT_QUERRY_WORDQUERY_H


#include <string>

#include "Query_base.h"
#include "QueryResult.h"
#include "TextQuery.h"


class WordQuery: public Query_base {
    friend class Query;     // Query uses the WordQuery constructor

    WordQuery(const std::string &s) : query_word(s) { }

    // concrete class: WordQuery defines all inherited pure virtual functions
    QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
    std::string rep() const { return query_word; }

    std::string query_word;     // word for which to search
};



#endif //YET_ANOTHER_TEXT_QUERRY_WORDQUERY_H
