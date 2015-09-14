/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          23-Jul-15, 03:36 PM
 *  Last updated:     24 Jul 2015, 12:32:42:220  
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
 *  Implementation file for the Exercise class.
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
********************************************************************************
*******************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>            // will randomize some numbers based on a time seed
#include <algorithm>
#include <iterator>         // std::istream_iterator
#include <functional>       // std::bind

#include "Exercise.h"

using std::placeholders::_1;        // needed for std::bind


void Exercise::A(const int elements_no)
{
    // We'll store some random ints in a vector.
    std::cout << "\n\nLet's say we have a nice little vector of "
              << elements_no << " ints..\n";
    std::vector<int> random_numbers;
    srand((unsigned)time(NULL));
    for (int i = 0; i != elements_no; ++i)
        random_numbers.emplace_back(rand());

    // Print vectors elements as to have proof the count is good.
    std::for_each(random_numbers.begin(), random_numbers.end(),
                  [] (const int &nr) { std::cout << "\t" << nr; });

    // Need to use std::bind because std::count_if has only a unary predicate
    // but std::greater requires two values to be compared.
    // A functor or an inplace defined lambda wouldn't need this
    auto more_than1024 = std::bind(std::greater<int>(), _1, 1024);

    // Now, with the help of a library function object count how many elements
    // have a value > 1024.
    int big_numbers = std::count_if(random_numbers.begin(),
                                    random_numbers.end(),
                                    more_than1024);
                                    //std::bind(std::greater<int>(), _1, 1024));

    std::cout << "\n\nIf we're to test how many of it's elements are > 1024"
              << "\nwe'd get.. : " << big_numbers << "\n";
}


void Exercise::B(void)
{
    std::cout << "\n\n\nSo we have a nice little poem,"
    << "\nwritten no doubt by some soon to be acclaimed poet.."
    << "\n\nLet's see what's the first word in the \"pooh_poem\""
    << "\n(other than pooh, of course).." << std::endl;

    std::ifstream poem("pooh_poem.txt", std::ifstream::in);

    // Need to use std::bind because std::find_if has only a unary predicate
    // but std::not_equal_to requires two values to be compared.
    // A functor or an inplace defined lambda wouldn't need this
    auto not_pooh = std::bind(std::not_equal_to<std::string>(), _1, "pooh,");
    std::istream_iterator<std::string> diff_word
        = std::find_if(std::istream_iterator<std::string>(poem),
                       std::istream_iterator<std::string>(),
                       not_pooh);


    std::cout << "....\n\t....\nSo it seems the first word different "
              << "from \"pooh\" (? ? !) is..\n\t-> " << *diff_word << "\n";
}


void Exercise::C(const int elements_no)
{
    // We'll store some random ints in a vector.
    std::cout << "\n\n\nLet's say we have a nice little vector of "
              << elements_no << " ints..\n";
    std::vector<int> random_numbers;
    srand((unsigned)time(NULL));
    for (int i = 0; i != elements_no; ++i)
        random_numbers.emplace_back(rand());

    // Print vectors elements as to have proof the count is good.
    std::for_each(random_numbers.begin(), random_numbers.end(),
                  [] (const int &nr) { std::cout << "\t" << nr; });

    // could've used a simpler loop, but the exercise required library functions
    std::transform(random_numbers.begin(),   // read all the elements
                   random_numbers.end(),     // of our vector
                   // store the transformed elements back in the same vector
                   random_numbers.begin(),
                   // will multiplicate the received argument by 2
                   std::bind(std::multiplies<int>(), _1, 2));

    std::cout << "\n\nIf we're to double the value of each elements,"
              << "\nWe'd have..\n";
    std::for_each(random_numbers.begin(), random_numbers.end(),
                  [] (const int &nr) { std::cout << "\t" << nr; });

    std::cout << '\n';
}


void Exercise::D(const int divident)
{
    // create a vector with 10 random int elements
    std::vector<int> random_numbers;
    srand((unsigned)time(NULL));
    for (size_t i = 0; i != 10; ++i)
        random_numbers.emplace_back(rand());
    std::cout << "\n\n\nLet's say we have a nice little vector of 10 ints.\n";
    std::for_each(random_numbers.cbegin(), random_numbers.cend(),
                 [] (const int &nr) { std::cout << nr << ' '; });

    // test to see if the received int is divisible by any objects of our vector
    std::vector<int> dividers;
    for (const int &nr : random_numbers) {
        double div_result = std::divides<float>() (divident, nr);
        // if the result is a whole number - a divider
        // store it in a vector to keep track of the dividers
        if (div_result == static_cast<int>(div_result))
            dividers.emplace_back(div_result);
    }

    size_t nr_of_div = dividers.size();   // avoid multiple size() calls
    switch (nr_of_div) {
        case 0:
            std::cout << "\n\nIt looks like none of the elements of our vector"
                      << "\n is a valid divider for " << divident;
            break;
        case 1:
            std::cout << "\n\nIt looks like just one number from our vector"
                      << "\nis a valid divisor for " << divident
                      << " : " << dividers.at(0);
            break;
        case 2:
        default:
            std::cout << "\n\nIt seems like there are actually " << nr_of_div
                      << " divisors for " << divident << " in our vector:\n";
            for (const int &nr : dividers)
                std::cout << nr << ' ';
            break;
    }

    std::cout << ".\n\n";
}