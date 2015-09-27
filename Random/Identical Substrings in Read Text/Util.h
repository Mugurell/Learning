/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          23-Sep-15, 06:19 PM
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
 *  --- 
 *
********************************************************************************
*******************************************************************************/



#ifndef IDENTICAL_SUBSTRINGS_IN_READ_TEXT_UTIL_H
#define IDENTICAL_SUBSTRINGS_IN_READ_TEXT_UTIL_H


#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>


namespace Util {

    // Read all text from the file indicated by user, store it in a vector.
    std::vector<std::string>
            ReadTextFromFile(const std::string &inputFileName);

    // Form sliding windows of al leat 3 chars for every word from text read.
    std::map<std::string, std::vector<std::string>>
            FormSlidingWindows(const std::vector<std::string> &text);

    // Print the words that share the same identical substrings,
    // or an appropriate message if there is no match.
    void PrintFoundDuplicates
            (const std::map<std::string, std::vector<std::string>> &words);

}

#endif //IDENTICAL_SUBSTRINGS_IN_READ_TEXT_UTIL_H
