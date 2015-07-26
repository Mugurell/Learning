/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          21 Jul 2015, 18:45:16:007
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
 *  Exercise 14.35: Write a class like PrintString that reads a line of input
 *  from an istream and returns a string representing what was read. If the
 *  read fails, return the empty string.
 *  Exercise 14.36: Use the class from the previous exercise to read the
 *  standard input, storing each line as an element in a vector.
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



#include <iostream>

#include "PrintString.h"


int main()
{
    std::cout << "\n\nLet's read a line of text from std::cin..."
              << "\nCan you help me a little?\n\tStart typing!\n";

    PrintString readOneLine;
    std::string lineRead = readOneLine();

    std::cout << "\n\"" << lineRead << "\"\n\n\tThat's all you've got?"
              << "\n\tType moar !" << std::endl;

    PrintString readUntilEnd;
    std::vector<std::string> inputRead;
    while (!(lineRead = readUntilEnd()).empty())
        inputRead.emplace_back(lineRead);

    std::cout << "\n\nSo now you've said..\n\"";
    for(auto eachLine : inputRead) {
        std::cout << eachLine << std::endl;
    }

    std::cout << "\"\n\nOk.\n\tBye\n\n";
    return 0;
}