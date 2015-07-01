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


#include <sstream>

#include "FileOperations.h"
#include "StringBlobPtr.h"


/*
 * Ask for an input file.
 * Return an ifstream initialized with that file name.
 */
std::ifstream
getInputFile() {
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
	bool validity = false;
	if (inputFile) {
		std::string buffer;
		std::getline(inputFile, buffer);
		for (const auto & eachCharacter : buffer) {
			// 33 should be the first nonwhitespace char and 126 the last
			if (eachCharacter >= 33 && eachCharacter <= 126) {
				validity = true;
				break;
			}
		}
	}

	return validity;
}


/*
 * This is the most important one!
 * In this function we'll read a line at a time from the inputFile, and store
 * that text into a new StringBlob object.
 */
const StringBlob&
readInputFile(std::ifstream inputFile) {
	StringBlob inputFileText;
	std::string eachWord, eachLine;

	while (std::getline(inputFile, eachLine)) {
		std::istringstream lineRead(eachLine);
		while (lineRead >> eachWord)
			inputFileText.pushBack(eachWord);
		inputFileText.pushBack("\n");
	}

	return inputFileText;
}


/*
 * Here we'll take a StringBlob object and print it's content (vector<string>)
 * one string at a time.
 */
std::ostream&
printInputFile(const StringBlob& inputFileText, std::ostream &ostream) {
	StringBlobPtr linesOfText(inputFileText.begin(), inputFileText.end());

	// Print each word using StringBlobPtr member functions.
	// StringBlobPtr has a member function to check when it should stop.
	std::string wordBuffer;
	for (linesOfText.iCurrentWord = 0;
	     wordBuffer = linesOfText.getCurrentWord();
	     linesOfText.incrementWordPointer()) {
		ostream << wordBuffer;
	}

	return ostream;
}
