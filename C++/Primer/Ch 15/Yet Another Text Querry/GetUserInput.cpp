/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          05 Jul 2015, 16:25
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
 *  Implementation file for GetUserInput.h.
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



#include "GetUserInput.h"


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