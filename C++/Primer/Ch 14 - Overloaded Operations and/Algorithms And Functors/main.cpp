/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          21 Jul 2015, 21:33:00:975
 *  Last updated:     22 Jul 2015, 17:02:25:023
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
 *  Exercise 14.37: Write a class that tests whether two values are equal.
 *  Use that object and the library algorithms to write a program to replace all
 *  instances of a given value in a sequence
 *
 *  Bugs:
 *  In current implementation if the word replacement have more characters than
 *  the replaced, the original formatting (all lines <= 80 characters)
 *  will be lost.
 *  To implement another function to reformat the outputted text far exceeds
 *  the proof of concept (algorithms and functors) that this exercise required.
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  Function objects are most often used as arguments to the generic algorithms.
 *
 *  The try catch block is just for fun. Completely unneeded.
 *
 *  Cluttered the main just because it's more verbose.
 *
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <fstream>
#include <stdexcept>    // for std::runtime_error
#include <algorithm>    // for std::for_each
#include <iterator>     // for std::istream_iterator
#include <sstream>

#include "ReplaceDupes.h"


int main()
{
    std::cout << "\n\nSo we have a nice little random text."
              << "\nLet's do some editing."
              << "\nLet's change some words..";

    std::string dupeWord, replaceWith;

    // make sure the word are entered/saved properly
    bool readSuccessfully = false;
    while (!readSuccessfully) {
        std::cout << "\nPlease enter the word you want to replace and the word"
                  << "\nyou want to replace it with -> ";
        try {
            std::cin >> dupeWord >> replaceWith;
            // if the read failed ( if (!std::cin)) throw a runtime_error
            // and ask the user if he want to try again
            if (std::cin.rdstate() == std::cin.failbit)
                throw std::runtime_error ("Seems like there was an error in "
                                          "reading the input.");
            else
                readSuccessfully = true;
        }
        catch (std::runtime_error err) {
            std::cerr << err.what();
            std::cin.clear();               // clear any fail flags
            std::cin.ignore(100, '\n');     // clear any input left in buffer

            std::cout << "\nTry again? [Y] / [N] -> ";
            char choice;
            std::cin >> choice;
            // convert the char read to uppercase
            (choice >= 'a' && choice <= 'z') ?
                choice -= 'a' - 'A' : choice == choice;
            switch (choice) {
                case 'Y':
                    break;
                case 'N':
                default:
                    std::cout << "\n\nOk, bye.\n\n";
                    return 0;
            }
        }
    }

    // Create a functor that will replace first parameter with the second.
    // Add an ending space because the strings read below
    // will also contain an ending space.
    ReplaceDupes replaceWords(dupeWord += " ", replaceWith += " ");

    std::ifstream inputFile;
    inputFile.open("random_text.txt", std::ifstream::in);
    if (inputFile.is_open()) {
        // open a new file on disk as to be used as output file
        std::ofstream outputFile;
        outputFile.open("deduplicated_text.txt", std::ofstream::out);

        if (outputFile) {   // implicit check if it was successfully opened
            std::vector<std::string> inputFileText;
            std::string line, word;
            while (std::getline(inputFile, line)) {
                std::istringstream lineBuffer(line);    // hold each line read
                while (lineBuffer >> word) {
                    inputFileText.push_back(word += " ");
                }
                inputFileText.push_back("\n");    // bc getline discards newline
            }

            inputFile.close();

            std::transform(inputFileText.begin(),
                           inputFileText.end(),
                           std::ostream_iterator<std::string>(outputFile),
                           replaceWords);

            outputFile.close();

// This will not keep the initial formatting!!!
//
//            //inputFile >> std::noskipws;
//
//            std::transform(// starting at beginning of inputFile
//                            std::istream_iterator<std::string> (inputFile),
//                           // and to the end of it
//                            std::istream_iterator<std::string>(),
//                           //save content starting at begin of 'outputFile'
//                            std::ostream_iterator<std::string>(outputFile),
//                           //while performing 'replaceWords' on every element
//                           replaceWords);
////////////////////////////////////////////////////////////////////////////

        }
        else
            std::cout << "\nCannot open output file.\nExiting...\n\n\tBye.\n\n";
    }
    else
        std::cout << "\nCannot open input file.\nExiting...\n\n\tBye.\n\n";

    return 0;
}