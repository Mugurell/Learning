/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          03 Jul 2015, 06:40 PM
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
 *  Implementation file for the QueryResult class.
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



#include "QueryResult.h"


QueryResult::QueryResult(std::string searchedWord_,
                         std::shared_ptr<std::set<lineNo>> lineNo_,
                         std::shared_ptr<std::vector<std::string>> inputFName_)
        : searchedWord(searchedWord_), lineNumber(lineNo_), file(inputFName_) {}


std::ostream&
print(std::ostream &os, const QueryResult &qr) {
    // if the word was found, print the count and all occurrences
    os << "\n\n" << qr.searchedWord << " occurs " << qr.lineNumber->size()
       << (qr.lineNumber->size() == 1 ? " time." : " times.") << std::endl;

    // Ask the user if he wants all the lines on which that word appears
    // to be printed
    std::cout << "\nDo you want to see the lines on which " << qr.searchedWord
    << " appears?\n\t [Y] / [N] -> ";
    char usersChoice;
    std::cin >> usersChoice;
    if (usersChoice >= 'a' && usersChoice <= 'z')
        usersChoice -= 'a' - 'A';
    switch (usersChoice) {
        case 'Y':
            for (auto lineNr : *qr.lineNumber) {
                // for every element in the set
                // don't confound the user with text lines starting at 0
                os << "\tline " << lineNr + 1 << ":\n"
                << *(qr.file->begin() + lineNr) << std::endl;
            }
            break;
        case 'N':
            // fallthrough
        default:
            std::cout << "\nI understand." << std::endl;
            break;
    }

    return os;
}