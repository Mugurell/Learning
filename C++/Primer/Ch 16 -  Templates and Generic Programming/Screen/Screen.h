/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          17-Aug-15, 09:59 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Exercise 16.14: Write a Screen class template that uses nontype parameters
 *  to define the height and width of the Screen.
 *  Exercise 16.15: Implement input and output operators for your Screen
 *  template. Which, if any, friends are necessary in class Screen to make the
 *  input and output operators work? Explain why each friend declaration,
 *  if any, was needed.
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



#ifndef SCREEN_SCREEN_H
#define SCREEN_SCREEN_H


#include <cstddef>
#include <iostream>
#include <string>


template <size_t H, size_t W>
class Screen {
    // fill the screen with a character read from cin
    friend std::istream& operator>>(std::istream&, Screen &);

    // print each row
    friend std::ostream& operator<<(std::ostream&, const Screen&);

public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(H, W, pos c = 0, char ch = '*')
        : height(H), width(W), cursor(c), contents(H * W, ch) { }

    char get() const { return contents.at(cursor)};

    // move the cursor at a new position
    Screen& move_at(pos h, pos w);

private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
};



#endif //SCREEN_SCREEN_H
