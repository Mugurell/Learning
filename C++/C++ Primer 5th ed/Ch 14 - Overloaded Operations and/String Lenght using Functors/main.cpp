/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          22 Jul 2015, 21:38:41:344
 *  Last updated:     22 Jul 2015, 23:14:24:988
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
 *  Exercise 14.38: Write a class that tests whether the length of a given
 *  string matches a given bound. Use that object to write a program to report
 *  how many words in an input file are of sizes 1 through 10 inclusive.
 *  Exercise 14.39: Revise the previous program to report the count of words
 *  that are sizes 1 through 9 and 10 or more.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  Remember than a lambda is nothing else than a function class object
 *  created right then, in place by the compiler.
 *  So, when a lambda captures a variable by reference, it is up to the program
 *  to ensure that the variable to which the reference refers exists when the
 *  lambda is executed . 
 *  Therefore, the compiler is permitted to use the reference directly without
 *  storing that reference as a data member in the generated class.
 *  In contrast, variables captured by value are copied into the lambda. 
 *  As a result, classes generated from lambdas that capture variables by value
 *  have data members corresponding to each such variable. These classes also
 *  have a constructor to initialize these data members from the value of the 
 *  captured variables. 
 *  
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>    // for_each
#include <iterator>     // std::istream_iterator

#include "SizeTest.h"


int main()
{
    std::cout << "\n\nWe'll now gonna open a nice text file..,"
              << "\nand test to see the lenght of it's words."
              << "\n\nTell me what number of character should a word have"
              << "\nas minimum? -> ";
    size_t min_nr, max_nr;
    std::cin >> min_nr;
    std::cout << "\nAnd what's the maximum number of characters"
              << "\nit should have? -> ";
    std::cin >> max_nr;

    std::ifstream inputFile("random_text.txt", std::ifstream::in);
    std::string::difference_type valid_words, more_than_10;

    // will be captured by the lambda by value and so will be used in the
    // constructor to initialize lambda's unnamed class's member variables
    std::string::size_type ten = 10, fara_numar = 999;

    if (inputFile) {    // implicit check if input file was opened successfully
        // SizeTest one_ten(min_nr, max_nr);
        valid_words= std::count_if
                     (std::istream_iterator<std::string>(inputFile),
                      std::istream_iterator<std::string>(),
                      SizeTest(min_nr, max_nr));
                     // one_ten);

        // And now to comply with the exercise requirement (sort of..)
        // we'll gonna count again how many words with more than 10 characters
        // are in the inputFile.
        // Using a lamda (unnamed function of an unnamed class). Fun, fun, fun!!
        more_than_10 = std::count_if
                        (std::istream_iterator<std::string>(inputFile),
                        std::istream_iterator<std::string>(),
                        [ten, fara_numar](const std::string &word) {
                            std::string::size_type word_size = word.size();
                            return word_size >= ten && word_size <= fara_numar;
                        });
        inputFile.close();
    }
    else
        std::cerr << "\n...\n\tSorry but I couldn't open the default input file"
                  << "\n\n";

    std::cout << "\n\nSo it seems there were " << valid_words << " words"
              << "\nwith more than " << min_nr << " characters "
              << "but less than " << max_nr << ".\n"
              << "\nBut also " << more_than_10 << " words with more than "
              << ten << " and less than " << fara_numar << ".\n\n";

    return 0;
}