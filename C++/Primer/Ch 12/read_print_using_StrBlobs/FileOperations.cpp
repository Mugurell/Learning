/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          30 Jun 2015, 22:21
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
 *  --- This is a description of what the program does ---
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  Check where the break sends in isValid()
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



#include <iostream>


#include "FileOperations.h"
#include "StringBlob.h"


/*
 * Ask for an input file.
 * Return an ifstream initialized with that file name.
 */
std::ifstream
getInputFile(void v) {
	std::cout << "\nPlease enter the name of an input file:\n\t->";
	std::string inputFileName;
	std::cin >> inputFileName;

	return std::ifstream(inputFileName);
}

/*
 * Check if the file can be opened and if it contains any printable character.
 * Return a bool which will be used in main.
 */
bool
isValid(std::ifstream inputFile) {
	bool valid = false;
	if (inputFile) {
		std::string buffer;
		std::getline(inputFile, buffer);
		for (const auto & eachCharacter : buffer) {
			// 33 should be the first nonwhitespace char and 126 the last
			if (eachCharacter >= 33 && eachCharacter <= 126) {
				valid == true;
				break;
			}
		}
	}

	return valid;
}


/*
 * This is the most important one!
 * In this function we'll read a line at a time from the inputFile,
 * store that vector of strings in a shared_ptr<vector<string>> of StringBlob
 * and then print each string using StringBlobPtr.
 */
void
printInputFile(std::ifstream inputFile) {

}