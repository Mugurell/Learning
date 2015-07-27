/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          24 Jul 2015, 16:17:24:054
 *  Last updated:     24 Jul 2015, 21:56:11:837
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
 *  Exercise 14.44: Write your own version of a simple desk calculator that can
 *  handle binary operations.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  Got a little carried away... :-D
 *
********************************************************************************
*******************************************************************************/


#include <iostream>
#include <string>
#include <iomanip>      // both iomanip and limits needed for printing the
#include <limits>       // result - which is a double with full precision

#include "Functions.h"

#define ever (;;)       // Oppa K&R style!


int main()
{
    std::cout << "\n\nHi.\n\nMy name is Gicu."
              << "\nYou can consider me your personal, highly intelligent"
              << " virtual assistant."
              << "\n\nFor now I'm just gonna help you with math."
              << "\n\nIf you need my help just type a basic math operator"
              << "\nthen the operands, and I'll print it's result."
              <<"\n\n\t(Press 'Q' when you want me to take a hike)\n\n";

    for ever {
        //std::cin.ignore(100, '\n');
        std::cout << "Command: ";
        std::string terminal_line;
        std::getline(std::cin, terminal_line);
        int nr1 = 0, nr2 = 0;

        // Decrypt the user input and return what he probably intended (do math,
        // quit, test any implementation bugs). If he want math, we'll also
        // return nr1 and nr2 holding the operands.
        std::string operation =
                Functions::decrypt_gibberish(terminal_line, nr1, nr2);

        if (operation == "Q") {
            std::cout << "\n\tSo this is it?\n\tBye!\n\n";
            break;
        }

        if (operation == "+" || operation == "-" || operation == "/" ||
            operation == "*" || operation == "%")
        {
            double result = Functions::math[operation](nr1, nr2);
            std::cout <<
                    // set the precision for cout to be the one needed for
                    // doubles and + 1 because of rounding errors when printing
                    std::setprecision(std::numeric_limits<double>::digits10 + 1)
                      << "\n\t" << nr1 << ' ' << operation << ' ' << nr2
                      << " = " << result << ".\n\n";
        }
        else if (operation == "gibberish") {
            std::cout << "\n\tI was designed to do serious work, not fool"
                      << " around !\n\n";
        }
        else {
            std::cout << "\n\tOups! You didn't need to see this!"
                         << "\n\n\t:embarassed:\n\n";
        }
    }

    return 0;
}
