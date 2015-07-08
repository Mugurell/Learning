/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          03 Jul 2015, 11:33 AM
 *  Last updated:     07 Jul 2015, 16:54 
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
 *  Although we could write our program using vector, set, and map directly, it
 *  will be more useful if we define a more abstract solution.
 *  Hence this class, which will hold a vector and a map.
 *  The vector will hold the text of the input file; the map will associate
 *  each word in that file to the set of line numbers on which that word
 *  appears.
 *  This class will have a constructor that reads a given input file and an
 *  operation to perform the queries.
 *  The work of the query operation is pretty simple: It will look inside its
 *  map to see whether the given word is present. The hard part in designing
 *  this function is deciding what the query function should return. Once we
 *  know that a word was found, we need to know how often it occurred, the line
 *  numbers on which it occurred, and the corresponding text for each of
 *  those line numbers.
 *  For this we'll use a second class - QueryResult.
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



#ifndef QUERY_FILE_FOR_A_WORD_TEXTQUERY_H
#define QUERY_FILE_FOR_A_WORD_TEXTQUERY_H


#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <memory>


class QueryResult;      // needed for the return type in the query function

class TextQuery {
public:
    typedef std::vector<std::string>::size_type
            lineNo;         // type for the numbers of the lines in which the
                            // searched word

    // will create a new TextQuery object from an ifstream object
    TextQuery(std::ifstream &inputFile_);

    // Because the objects of the TextQuerry and QuerryResult classes are using
    // smart pointers to manage dynamic memory, we'll want to prevent copying
    TextQuery(const TextQuery&) = delete;
    TextQuery& operator=(const TextQuery&) = delete;

    // will return a QueryResult representing the lines on which
    // searchedWord appears.
    QueryResult query(const std::string& searchedWord) const;
private:
    std::shared_ptr<std::vector<std::string>>
            inputFileText;  // will hold all the text read line by line from
                            // the input file.
    std::map<std::string, std::shared_ptr<std::set<lineNo>>>
            wordsDatabase;  // map of each word to the set of the lines in
                            // which that word appears.
};


#endif //QUERY_FILE_FOR_A_WORD_TEXTQUERY_H
