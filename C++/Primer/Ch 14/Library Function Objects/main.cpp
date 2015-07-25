/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          23 Jul 2015, 15:12:04
 *  Last updated:     24 Jul 2015, 12:32:54:178  
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
 *  Exercise 14.42: Using library function objects and adaptors, define an
 *  expression to
 *  (a) Count the number of values that are greater than 1024
 *  (b) Find the first string that is not equal to pooh
 *  (c) Multiply all values by 2
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

#include "Exercise.h"


int main()
{
    std::string dashes(77, '-');
    // A. Will create a vector of random integers with the required number of
    // elements and test how many elements of it have a value of less than 1024.
    Exercise::A(10);
    std::cout << dashes;


    // B. Will read a small poem from a text file stored on disk
    // and print the first word in it which is different than "pooh" (??!)
    Exercise::B();
    std::cout << dashes;

    // C. Small function using an algorithm, an adaptor and a library function
    // object to multiply by two all the int elements from a vector with the
    // given number of elements
    Exercise::C(10);
    std::cout << dashes;

    // D. Test if the sent number can be divided by any of 10 random int
    // elements of a newly constructed vector.
    Exercise::D(21745);     // this was the first

    return 0;
}