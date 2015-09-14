//
//  Author:           Lingurar Petru-Mugurel
//  Written:          21 Aug 2015  21:57:19
//  Last updated:           ---
//
//
//  Description:
//   Exercise 16.14: Write a Screen class template that uses nontype
// parameters to define the height and width of the Screen.
// Exercise 16.15: Implement input and output operators for your Screen
// template.Which, if any, friends are necessary in class Screen to make the
// input and output operators work ? Explain why each friend declaration, 
// if any, was needed.
//
//  Bugs:
//    --- None ---
//
//  TODO:
//    --- None --- 
//
//  Notes:
//    --- 
//



#include <iostream>

#include "Screen.h"


int main()
{
    Screen<5, 5> scr;
    Screen<4, 60> scr2('$');

    // output src to the screen
    std::cout << "Here is a 5 * 5 matrix:" << std::endl;
    std::cout << scr;

    // input connet  to the  src 
    std::cout << "\n\nCool?"
        "\nYou can also change the displayed symbol."
        "\nWhat symbol you like more? -> ";
    std::cin >> scr;

    // test input
    std::cout << "\n\nCool!"
        << "\nLet's see that again:\n";
    std::cout << scr;

    std::cout << "\n\nAnd as a bonus, here's a big one:\n";
    std::cout << scr2 << "\n\n";


    return 0;
}