/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          08 Oct 2015, 13:18:45:364
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *   Exercise 17.11: Define a data structure that contains an integral object to
 *  track responses to a true/false quiz containing 10 questions. What changes,
 *  if any, would you need to make in your data structure if the quiz had 100
 *  questions?
 *   Exercise 17.12: Using the data structure from the previous question, write
 *  a function that takes a question number and a value to indicate a true/false
 *  answer and updates the quiz results accordingly.
 *   Exercise 17.13: Write an integral object that contains the correct answers
 *  for the true/false quiz. Use it to generate grades on the quiz for the data
 *  structure from the previous two exercises.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  Will be using bitsets.
 *
********************************************************************************
*******************************************************************************/



#include <iostream>

#include "Trivia.h"


int main()
{
    // Just a proof of concept; Will keep this simple.
    Trivia::Contestant a{"Marcu"};
    a.startGame();
    a.printResults();

    return 0;
}