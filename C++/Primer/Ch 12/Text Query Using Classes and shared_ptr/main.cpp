/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          03 Jul 2015, 11:02 AM
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
 *  program will let a user search a given file for words that might occur in
 *  it. The result of a query will be the number of times the word occurs and a
 *  list of lines on which that word appears. If a word occurs more than once
 *  on the same line, we’ll display that line only once. Lines will be displayed
 *  in ascending order—that is, line 7 should be displayed before line 9,
 *  and so on...
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Expected result:
 *  --- You can write here the execution command & the expected result ---
 *
 *  Notes:
 *  --- Anything that stands out ---
 *  --- Or needs to be treated with special attention ---
 *
*******************************************************************************
******************************************************************************/



#include "QueryResult.h"
#include "TextQuery.h"


std::string getInputFileName();
std::string getSearchedWord();

int main()
{
    std::cout << "\n\tWelcome to the amazing Text Query Program\n\n";

    // get a name for a valid file to be used as source for the search
    std::ifstream inputFile(getInputFileName());

    // build the query map for the input file
    TextQuery fileToBeSearched(inputFile);

    // prompt the user to type a word to which we'll base our search
    std::string searchedWord(getSearchedWord());

    // run the query and print the result
    print(std::cout, fileToBeSearched.query(searchedWord));

    std::cout << "\n\nPretty cool, huh?\n" << std::endl;

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
