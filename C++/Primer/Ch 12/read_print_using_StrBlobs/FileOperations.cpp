/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          30 Jun 2015, 22:21
 *  Last updated:     01 Jul 2015, 18:07 
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
 *  Implementation file for FileOperations.h.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  Showstopper bug in read() in line 'inputFileText.pushBack(eachWord).
 *  Seems like I get a segmentation fault because the shared_ptr (member of
 *  inputFileText - StringBlobPtr) hasn't allocated enough space for the vector
 *  to grow.
 *  strikeout ATM don't know how to resolve this. /strikeout
 *  Resolved in StringBlob.cpp !!!
 *
*******************************************************************************
******************************************************************************/


#include <sstream>

#include "FileOperations.h"
#include "StringBlobPtr.h"


/*
 * Ask for an input file.
 * Return an ifstream initialized with that file name.
 */
std::string getInputFileName(void) {
    std::cout << "\nPlease enter the name of an input file:\n\t-> ";
    std::string inputFileName;
    std::cin >> inputFileName;

    return inputFileName;
}


/*
 * Check if the file can be opened and if it contains any printable character.
 * Return a bool which will be used in main.
 */
bool
isValid(std::string inputFileName) {
    std::ifstream inputFile(inputFileName, std::ifstream::in);
    bool validity = false;
    if (inputFile) {
        std::string buffer;
        std::getline(inputFile, buffer);
        for (const auto & eachCharacter : buffer) {
            // 33 should be the first non-whitespace char and 126 the last
            if (eachCharacter >= 33 && eachCharacter <= 126) {
                validity = true;
                break;
            }
        }
    }

    return validity;
}


/*
 * In this function we'll read a line at a time from the inputFile, and store
 * that text into a new StringBlob object.
 */
StringBlob
read(std::string inputFileName) {
    std::ifstream inputFile(inputFileName, std::ifstream::in);
    StringBlob inputFileText;
    std::string eachWord, eachLine;

    while (std::getline(inputFile, eachLine)) {
        std::istringstream lineRead(eachLine);
        while (lineRead >> eachWord)
            inputFileText.pushBack(eachWord + " ");
        inputFileText.pushBack("\n");
    }

    return inputFileText;
}


/*
 * Here we'll take a StringBlob object and print it's content (vector<string>)
 * one string at a time.
 */
std::ostream&
printInputFile(StringBlob& inputFileText, std::ostream &ostream) {
    for (StringBlobPtr first(inputFileText.begin()), last(inputFileText.end());
         first.iCurrentWord != last.iCurrentWord;
         first.incrementWordPointer()) {

        // Print each word using StringBlobPtr member functions.
        // StringBlobPtr has a member function to check when it should stop.
        ostream << first.getCurrentWord();
    }

    return ostream;
}

