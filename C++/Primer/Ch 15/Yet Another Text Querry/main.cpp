/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          06 Aug 2015, 19:45:38:810
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *  Text-querry program that will support the following queries:
 *  • Word queries find all the lines that match a given string;
 *  • Not queries, using the ~ operator, yield lines that don’t match the query;
 *  • And queries, using the & operator, return lines matching both queries;
 *  • Or queries, using the | operator, return lines matching either one
 *  of the two queries;
 *  • Even combinations of those above!
 *
 *  .. with the help of the beautiful inheritance
 *
 *                          -------------
 *                          | Query_base|
 *                          -------------
 *                          /     |     \
 *                       /        |        \
 *                    /           |           \
 *                 /              |              \
 *           ------------    -----------     --------------
 *           |WordQuerry|    |NotQuerry|     |BinaryQuerry|
 *           ------------    -----------     --------------
 *                                              /      \
 *                                            /          \
 *                                          /              \
 *                                        /                  \
 *                                   -----------         ----------
 *                                   |AndQuerry|         |OrQuerry|
 *                                   -----------         ----------
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
#include <fstream>

#include "QueryResult.h"
#include "GetUserInput.h"
#include "Query.h"
#include "OrQuery.h"
#include "NotQuery.h"
#include "AndQuery.h"


int main()
{
    std::cout << "\n\tWelcome to the amazing Text Query Program\n\n";

    // get a name for a valid file to be used as source for the search
    std::ifstream inputFile(getInputFileName());

    // build the query map for the input file
    TextQuery fileToBeSearched(inputFile);



    /*
     * Currently the implementation of this exercise imply that user will
     * explicitly create it's query items.
     */

    // Create any number of Querys you like,
    // Link them together using any of the 3 operators from the description
    // in main, using normal c++ precedence rules.
    Query search_for =
            (Query("dinosaurs") & ~Query("high")) | Query("mushrooms") ;

    std::cout << "\nExecuting query for: " << search_for << std::endl;
    auto results = search_for.eval(fileToBeSearched);
    // report matches
    print(std::cout, results);


    std::cout << "\n\nPretty cool, huh?\n" << std::endl;
    return 0;
}
