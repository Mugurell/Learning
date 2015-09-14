/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          03 Jul 2015, 11:33 AM
 *  Last updated:     03 Jul 2015, 03:52 PM
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
 *  Exercise 12.28: Write a program to implement text queries without defining
 *  classes to manage the data. Your program should take a file and interact
 *  with a user to query for words in that file. Use vector, map, and set
 *  containers to hold the data for the file and to generate the results for
 *  the queries.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  The headers string and cctype are apparently not needed.
 *  Probably included by the other headers.
 *
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <iterator>         // back_inserter()
#include <algorithm>        // remove_copy_if()


std::string getInputFileName();
std::string getSearchedWord();

// This function will search the file named inputFileName for the word
// searchedWord with the help of a database constructed in another function.
// If the searched word is found, will print the number of times that word 
// occurs in the file and, if the user wants - the content of each line on which
// that word occurs.
void textQuery(const std::string inputFileName, const std::string searchedWord);

// This function takes a string that represents a file name as argument,
// reads that file and constructs a database of the words in it, storing it
// in a map whose key is each word from the file and it's value is a set of the
// line numbers on which that word appear in the file. Returns that map.
std::map<std::string, std::set<std::vector<std::string>::size_type>>
        constructWordsDatabase(const std::string inputFileName);


int main()
{
    std::cout << "\n\tWelcome to the amazing Text Query Program\n\n";
    std::string inputFileName = getInputFileName();
    std::string searchedWord = getSearchedWord();
    textQuery(inputFileName, searchedWord);

    std::cout << "\nPretty cool, huh?\n" << std::endl;
}


std::string getInputFileName()
{
    std::cout << "\nPlease input the filename to be searched,\n"
              << "Or press 'Q' to quit\n\t-> ";
    std::string inputFileName;
    std::ifstream inputFile;
    bool valid = false;
    while (!valid) {
        std::cin >> inputFileName;
        if (inputFileName == "q" || inputFileName == "Q")
            exit (0);
        inputFile.open(inputFileName, std::ifstream::in);
        // test to see if the name is there is a file with that name
        if (inputFile) {
            std::string lineBuffer;
            std::getline(inputFile, lineBuffer);
            // if the file could be opened test to see if it contains any printable
            // characters - it is not empty.
            for (const char &eachChar : lineBuffer) {
                if (eachChar >= 33 && eachChar <= 126) {
                    valid = true;
                    break;
                }
            }
            // if there were no valid characters in the first line of the file,
            // assume it is blank, ask the user for a new file.
            if (valid)
                break;
            std::cout << "\nFile is empty.\n";
        }
        else {
            std::cout << "\nFile couldn't be opened.\n";
        }
        std::cout << "Try again, or press 'Q' to quit: -> ";
    }
    if (inputFile)
        inputFile.close();

    return inputFileName;
}


std::string getSearchedWord()
{
    std::cout << "\n\nSo we have a valid input file."
    << "\nWhat word are you curious about..? -> ";
    std::string searchedWordName;
    std::cin >> searchedWordName;
    return searchedWordName;
}


std::map<std::string, std::set<std::vector<std::string>::size_type>>
constructWordsDatabase(const std::string inputFileName)
{
    std::ifstream inputFile(inputFileName, std::ifstream::in);
    std::map<std::string, std::set<std::vector<std::string>::size_type>>
            database;
    std::vector<std::string> fileContent;
    decltype(fileContent.size()) lineNo{0};

    for (std::string line; std::getline(inputFile, line); ++lineNo) {
        fileContent.push_back(line);
        std::istringstream lineStream(line);
        // store only strings that are not punctuation characters.
        // this can be used or not.
        for (std::string text, word; lineStream >> text; word.clear()) {
            std::remove_copy_if(text.begin(), text.end(),  // source iterators
                                std::back_inserter(word),  // output iterator
                                ispunct);    // unary predicate (don't copy if
            //                                                  is punctuation)
            database[word].insert(lineNo);
        }
    }

    inputFile.close();
    return database;
}


// Use the database returned by constructWordsDatabase().
void textQuery(const std::string inputFileName, const std::string searchedWord)
{
    auto wordsDatabase = constructWordsDatabase(inputFileName);
    decltype(wordsDatabase)::iterator foundWord =
            wordsDatabase.find(searchedWord);
    std::ifstream inputFile;
    std::vector<std::string> fileContent;

    if (foundWord != wordsDatabase.end()) {
        // if the searched word was found, must read again the file into a
        // vector to print the line(s) on which that word occurs.
        inputFile.open(inputFileName, std::ifstream::in);
        std::string lineRead;
        while (std::getline(inputFile, lineRead))
            fileContent.push_back(lineRead);
        inputFile.close();

        // if the word was found, test to see how many times that word is 
        // repeating (check the set's size).
        std::cout << searchedWord << " occurs " << foundWord->second.size()
        << (foundWord->second.size() > 1 ? " times" : " time")
        << ".\n" << std::endl;

        // Ask the user if he want all the lines on which that word appears
        // to be printed
        std::cout << "\nDo you want to see the lines on which " << searchedWord
        << " appears?\n\t [Y] / [N] -> ";
        char usersChoice;
        std::cin >> usersChoice;
        if (usersChoice >= 'a' && usersChoice <= 'z')
            usersChoice -= 'a' - 'A';
        switch (usersChoice) {
            case 'Y':
                // std::vector::at which returns a reference to the element at
                // the indicated position (line number).
                for (auto lineNo : foundWord->second)
                    std::cout << "\tline " << lineNo + 1 << ":\n"
                    << fileContent.at(lineNo) << std::endl;
                break;
            case 'N':
                // fallthrough
            default:
                std::cout << "\nI understand." << std::endl;
                break;
        }
    }
    else
        std::cout << "\n\nSorry but " << searchedWord << " was not found in "
                  << inputFileName << '.' << std::endl;
}