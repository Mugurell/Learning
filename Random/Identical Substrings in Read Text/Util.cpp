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


#include <utility>

#include "Util.h"


std::vector<std::string>
Util::ReadTextFromFile(const std::string &inputFileName)
{
    // try to open the file with the received path
    std::ifstream inputFile(inputFileName, std::ifstream::in);
    if (!inputFile.is_open())
    {
        std::cerr << "\n\tError: Can't open " << inputFileName
                << "for reading.";
        exit(0);
    }

    // read the word by word and save all into a vector
    std::string readWord;
    std::vector<std::string> readText;
    while (inputFile >> readWord)
        readText.emplace_back(readWord);
    inputFile.close();

    // check if we read at least 2 words
    if (readText.size() < 2)
    {
        std::cerr << "\n\tError: Can't read the minimum 2 words.";
        exit(0);
    }

    return readText;
}


std::map<std::string, std::vector<std::string>>
Util::FormSlidingWindows(const std::vector<std::string> &text)
{
    std::map<std::string, std::vector<std::string>> wordsSubstrings;
    unsigned count;

    for (std::string word : text)
    {
        count = 0;
        while (word.size() - count >= 3)
        {
            // subscripting a map returns the mapped type - here, a vector
            // we fill that vector with sliding windows of 3 characters
            wordsSubstrings[word].push_back(word.substr(count++, 3));
        }
    }

    // check if we have at least 2 keys in our container (we need a pair)
    if (wordsSubstrings.size() < 2)
    {
        std::cerr << "\n\tError: Not even 2 words with 3 or more characters .";
        exit(0);
    }

    return wordsSubstrings;
}


void Util::PrintFoundDuplicates
        (const std::map<std::string, std::vector<std::string>> &words)
{
    // pair the words that have at least 2 substrings in common
    std::pair<std::string, std::string> related_words;
    // "shared" substrings between the 2 words. At least 2 substrings.
    std::vector<std::string> identical_substrings;

    bool found_at_least_one_common_substring = false;

    // To iterate through every pair in our map and compare every mapped type's
    // (vector of strings) elements I'll use an approach loops similar to
    // those used for simple bubble sort.
    // No random access iterators for maps, so I can't do end - 1 for example
    auto end1 = --words.cend();
    auto end2 =   words.cend();

    // compare starting at the first value_type in our map
    for (auto beg1 = words.cbegin(); beg1 != end1; ++beg1)
    {
        // don't want the original iterator incremented in the next for loop
        auto beg1_dupe = beg1;

        // identical_substrings.clear();

        // with the next immediate value_type
        for (auto beg2 = ++beg1_dupe; beg2 != end2; ++beg2)
        {
            // form the pair of words that potentially can have the
            // same substrings
            related_words = {beg1->first, beg2->first};

            identical_substrings.clear();

            // every substring in beg1's mapped_type (vector of strings)
            for (const std::string &word1 : beg1->second)
            {
                // with every substring beg2's mapped type (vector of strings)
                for (std::string word2 : beg2->second)
                {
                    if (word1 == word2)
                    {
                        found_at_least_one_common_substring = true;
                        identical_substrings.emplace_back(word2);
                    }
                }
            }

            if (identical_substrings.size() >= 2)
            {
                std::cout << "\"" << related_words.first << "\" and \""
                        << related_words.second << "\" have in common\n\t: ";
                for (auto substring : identical_substrings)
                    std::cout << substring << ' ';
                std::cout << std::endl;
            }
        }
    }

    if (!found_at_least_one_common_substring)
        std::cout << "\n\t\"fara solutie\"\n";
}
