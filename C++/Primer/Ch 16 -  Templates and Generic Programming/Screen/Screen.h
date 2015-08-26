/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          17-Aug-15, 09:59 PM
 *  Last updated:     21 Aug 2015  20:11:07
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
 *  About declaring the overloaded operators as templates or not, see
 *  http://stackoverflow.com/questions/13932088/
 *
********************************************************************************
*******************************************************************************/



#ifndef SCREEN_SCREEN_H
#define SCREEN_SCREEN_H


#include <cstddef>
#include <iostream>
#include <string>


/**
 * Forward declarations needed for to declare the overloaded i/o operators
 * without declaring it as a function template in the class body
 */
template<std::size_t H, std::size_t W> class Screen;
template<std::size_t T1, std::size_t T2>
std::ostream& operator<<(std::ostream&, const Screen<T1, T2>&);
template<std::size_t T1, std::size_t T2>
std::istream& operator>>(std::istream&, Screen < T1, T2>&);


template<std::size_t H, std::size_t W>
class Screen
{
    /**
     * This would be the correct way to befriend the i/o operators
     * .. If I didn't use the forward declaration method..
     */
    //template<std::size_t T1, std::size_t T2> 
    //friend ostream& operator<< (ostream &, Screen<T1, T2>&);
    //template<std::size_t T1, std::size_t T2>
    // friend istream& operator>>(istream&, Screen<T1, T2>&);

    friend std::istream& operator>> <> (std::istream&, Screen&);
    friend std::ostream& operator<< <> (std::ostream&, const Screen&);

private:
    using pos = std::string::size_type;

    pos height = 0;
    pos width = 0;
    pos cursor = 0;
    std::string contents;

public:
    // Screen() = default;  

    // a constructor which init all members is a default one
    Screen(char ch = '*') : height(H), width(W), contents(H * W, ch) { }

    // get the symbol at the current cursor position
    char get() const { return contents.at(cursor); }

    // move the cursor at the indicated position
    Screen& move_at(pos l, pos w);
};


#include "Screen.tpp"

#endif //SCREEN_SCREEN_H