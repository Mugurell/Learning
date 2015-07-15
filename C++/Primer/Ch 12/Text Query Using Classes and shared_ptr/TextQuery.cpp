/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          03 Jul 2015, 11:33 AM
 *  Last updated:     10 Jul 2015, 19:38:59:588
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
 *  Implementation file for the TextQuerry class.
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



#include <new>
#include <sstream>
#include <algorithm>

#include "TextQuery.h"
#include "QueryResult.h"


// will read the input file and build the map of lines to line numbers
TextQuery::TextQuery(std::ifstream &inputFile_)
    : inputFileText(new StrVec) {
    std::string lineRead;
    while (std::getline(inputFile_, lineRead)) {        // for each line in file
        inputFileText->push_back(lineRead);        // remember this line of text
        int currentLineNo = inputFileText->size() - 1;  // current line number
        std::istringstream lineStream(lineRead); // separate the line into words
        std::string word;
        while (lineStream >> word) {             // for each word in that line
            // if word isn't already in wordsDatabase, subscripting adds a
            // new entry (the value in wordsDatabase).
            // lines is a reference, so changes made to lines will be made
            // to the element in wordsDatabase.
            std::shared_ptr<std::set<lineNo>> &lines = wordsDatabase[word];
            if (!lines)     // that pointer is null the first time we see 'word'
                lines.reset(new std::set<lineNo>);   // allocate a new set

            // because lines is a reference, the call to insert adds an
            // element to the set in wordsDatabase.
            lines->insert(currentLineNo);
        }
    }
}


QueryResult
TextQuery::query(const std::string &searchedWord) const {
    // we'll return a pointer to this set if we don't find sought
    static std::shared_ptr<std::set<lineNo>> noData(new std::set<lineNo>);
    //using find and not a subscript to avoid adding words to wordsDatabase
    auto loc = wordsDatabase.find(searchedWord);
    if (loc == wordsDatabase.end())
        return QueryResult(searchedWord, noData, inputFileText);   // not found
    else
        return QueryResult(searchedWord, loc->second, inputFileText);
}
