/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10 Jul 2015, 21:45:43:247
 *  Last updated:     17 Jul 2015, 13:07:19:126
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
 *  Exercise 13.44: Write a class named String that is a simplified version of
 *  the library string class. Your class should have at least a default
 *  constructor and a constructor that takes a pointer to a C-style string.
 *  Use an allocator to allocate memory that your String class uses.
 *  Exercise 13.47: Give the copy constructor and copy-assignment operator in
 *  your String class from exercise 13.44 in § 13.5 (p. 531) a statement that
 *  prints a message each time the function is executed.
 *  Exercise 13.48: Define a vector<String> and call push_back several times on
 *  that vector. Run your program and see how often Strings are copied.
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
#include <chrono>
#include <vector>

#include "String.h"


int main()
{
    auto t0 = std::chrono::high_resolution_clock::now();
    std::cout << "\n\n**This is just a test!**\n\n";

    /********************************************************************
     * Ex 13.48
     * So after calling push_back 5 times I see that
     * - the copy constructor would be used 11 times
     * - the move constructor would be used 12 times. But no copying!
     */
    std::vector<String> wise_words;
    wise_words.push_back("Time ");
    wise_words.push_back("is ");
    wise_words.push_back("a ");
    wise_words.push_back("valuable ");
    wise_words.push_back("thing!");


    /*******************************************************************
     * Test the functions for equality operations.
     */
    String one;// = "Cocojambo";
    String two;// = "Cocojambo";

    if (one == two)
        std::cout << "\nThey really are equal?\n";


    /******************************************************************
     * Test the functions for relational operators
     */
    if (one >= two)
        std::cout << "\nYou're instinct was right!\n";
    else
        std::cout << "\nHmmm... you we're wrong it seems..\n";


    /******************************************************************
     * Print the time it took to execute this program. Just for fun.
     */
    std::chrono::high_resolution_clock::time_point
        t1 = std::chrono::high_resolution_clock::now();
    std::cout << "\n\nTime it took to run this program: "
              << std::chrono::duration_cast<std::chrono::microseconds>
                                          (t1 - t0).count()
              << " us.\n";

    return 0;
}