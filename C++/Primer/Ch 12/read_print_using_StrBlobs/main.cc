/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          30 Jun 2015, 14:16
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
 *  Exercise 12.19: Define your own version of StrBlobPtr and update your
 *  StrBlob class with the appropriate friend declaration and begin and end
 *  members.
 *  Exercise 12.20: Write a program that reads an input file a line at a time
 *  into a StrBlob and uses a StrBlobPtr to print each element in that StrBlob.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  The most complicated way to read and print a file.
 *  But nothing's stopping me!
 *
*******************************************************************************
******************************************************************************/


#include <fstream>

#include "StringBlobPtr.h"
#include "FileOperations.h"


int main()
{
    // Ask the user for a input file name stored on disk.
    std::string inputFileName = getInputFileName();

    // Try to open the file with that name and see if it contains any
    // characters.
    if (isValid(inputFileName)) {
        // If the file can be opened and is not empty, read that file line by
        // line into a StringBlob object (shared_ptr of a vector of strings
        // and then print that object using StringBlobPtr functions.
        StringBlob fileContent = read(inputFileName);
        std::cout << "\n\n";
        printInputFile(fileContent, std::cout);
    }
    else
        std::cout << "\nUnfortunatelly the entered filename isn't valid!\n";

    std::cout << "\n\nPretty cool, huh\n" << std::endl;

    return 0;
}
