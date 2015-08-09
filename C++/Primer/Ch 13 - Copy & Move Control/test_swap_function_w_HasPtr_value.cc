/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:                ---
**  Last updated:           ---
**
**  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**                    -Wmissing-format-attribute -Wmissing-include-dirs  
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
**
**  Execution:    ./...
**
**  Description:
**  Exercise 13.30: Write and test a swap function for your valuelike version of
**  HasPtr. Give your swap a print statement that notes when it is executed.
**  Exercise 13.31: Give your class a < operator and define a vector of
**  HasPtrs. Give that vector some elements and then sort the vector.
**  Note when swap is called.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  See http://bytes.com/topic/c/answers/170304-compiler-says-operator-needs
**            -exactly-one-argument-not-two-why
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <algorithm>        // for std::sort()

#include "HasPtr_class_act_like_value.h"



void thirty();          // appropriate for exercise 13.30
void thirtyone();       // appropriate for exercise 13.31

int main()
{

    thirtyone();


    std::cout << "\n\nPretty cool, huh?\n" << std::endl;
    return 0;
}


void thirty() {
    std::cout << "\nWe'll start by creating 2 objects of type Hasptr"
              << "\n\"one\":\n";
    HasPtr one("England", 546), two("France", 93284);
    one.print();
    std::cout << "\nAnd \"two\":\n";
    two.print();

    std::cout << "\nNow we'll gonna swap the two objects,";
    swap(one, two);
    std::cout << "And so we'll have:\n\"one\"\n";
    one.print();
    std::cout << "\nAnd \"two\":\n";
    two.print();
}


void thirtyone() {
    std::cout << "\nLet's create a vector of HasPtr objects..\n";
    std::vector<HasPtr> vec{
        {"Tokyo", 563},
        {"London", 324},
        {"London", 321},
        {"Bucale", 999},
        {"London", 001}
    };

    std::cout << "\nNow let's sort it..\n";
    std::sort(vec.begin(), vec.end());
    std::cout << "\nAnd so we'll have..\n";
    for(const HasPtr &each : vec)
        each.print();
}