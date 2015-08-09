//
// Created by Lingurar Petru-Mugurel on 25.05.2015.
//

/*
** This is just a little test for my huge a*s header
** as req by ex. 7.27.
*/

#include "Screen.cc"

int main()
{
    // initialize height w 5, width w 5 and contents w 5*5, 'X'
    Screen myScreen(5, 5, 'X');
    myScreen.display(std::cout);
    std::cout << std::endl;
    // move the cursor to position 4*width(5)
    // then on the result - (20) + 0 and set '#' as the content, then display.
    myScreen.move(4,0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n" << std::endl;

    return 0;
}