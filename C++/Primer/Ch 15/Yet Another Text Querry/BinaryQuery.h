/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          07-Aug-15, 02:38 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  The BinaryQuery class is an abstract base class that holds the data needed
 *  by the query types that operate on two operands.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  The BinaryQuery class does not define the eval function and so inherits a
 *  pure virtual. Thus, BinaryQuery is also an abstract base class, and we
 *  cannot create objects of BinaryQuery type.
 *
********************************************************************************
*******************************************************************************/



#ifndef YET_ANOTHER_TEXT_QUERRY_BINARYQUERY_H
#define YET_ANOTHER_TEXT_QUERRY_BINARYQUERY_H


#include "Query_base.h"
#include "Query.h"


class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s)
            : lhs(l), rhs(r), opSym(s) { }

    // abstract class: BinaryQuery doesn't define eval
    std::string rep() const
        { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }

    Query lhs, rhs;     // right- and left-hand operands
    std::string opSym;  // name of the operator
};



#endif //YET_ANOTHER_TEXT_QUERRY_BINARYQUERY_H
