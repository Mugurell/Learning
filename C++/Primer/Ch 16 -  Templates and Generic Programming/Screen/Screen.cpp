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
 *  ---
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO: Recisteste treaba cu friendship la templateuri ca sa vezi cum
 *  aplici aici in cazurile operatorilor.
 *
 *  Notes:
 *  --- 
 *
********************************************************************************
*******************************************************************************/



#include "Screen.h"


// move the cursor to the given "coordinates"
template <std::size_t H, std::size_t W>
inline Screen<H, W>& Screen<H, W>::move_at(pos h, pos w)
{
    pos row = width * h;
    cursor = row + w;

    return *this;
}


std::istream& operator>>(std::istream &is, Screen &new_screen)
{
    char ch;
    is >> ch;
    std::string temp(Screen<H, W>height * Screen::width, ch);
    new_screen.contents = temp;

    return is;
}


