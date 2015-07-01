/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          30 Jun 2015, 14:16
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
 *  Expected result:
 *  --- You can write here the execution command & the expected result ---
 *
 *  Notes:
 *  --- Anything that stands out ---
 *  --- Or needs to be treated with special attention ---
 *
*******************************************************************************
******************************************************************************/


#include <fstream>

#include "StringBlobPtr.h"
#include "FileOperations.h"


int main()
{
	std::ifstream inputFile = getInputFile();
	isValid(inputFile);
	StringBlob inputFileText = readInputFile(inputFile);

	std::cout << printInputFile(inputFileText, std::cout);

	std::cout << "\n\nPretty cool, huh\n" << std::endl;

	return 0;
}
