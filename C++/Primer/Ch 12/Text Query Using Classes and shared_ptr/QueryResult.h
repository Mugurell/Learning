/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          03 Jul 2015, 11:49 AM
 *  Last updated:           ---
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
 *  The QueryResult class is intended to represent the results of a query.
 *  Once we know that a word was found, we need to know how often it occurred,
 *  the line numbers on which it occurred, and the corresponding text for each
 *  of those line numbers.
 *  These results include the set of line numbers associated with the given
 *  word and the corresponding lines of text from the input file. They are
 *  stored in objects of type TextQuery. Given that this class conceptually
 *  �share� data with TextQuerry, we�ll use shared_ptrs to reflect that
 *  sharing in our data structures.
 *  At the end. the data is to be printed by a member function.
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
*******************************************************************************
******************************************************************************/


#ifndef QUERY_FILE_FOR_A_WORD_QUERYRESULT_H
#define QUERY_FILE_FOR_A_WORD_QUERYRESULT_H


#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <set>


class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    typedef std::vector<std::string>::size_type
            lineNo;         // type for the numbers of the lines in which the

    QueryResult(std::string searchedWord_,
                std::shared_ptr<std::set<lineNo>> lineNo_,
                std::shared_ptr<std::vector<std::string>> inputFName_);
private:
    std::string searchedWord;           // word this query represents
    std::shared_ptr<std::set<lineNo>> lineNumber;    // lines it's on
    std::shared_ptr<std::vector<std::string>> file;  // input file
};


#endif //QUERY_FILE_FOR_A_WORD_QUERYRESULT_H