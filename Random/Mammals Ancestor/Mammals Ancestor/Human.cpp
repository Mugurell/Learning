//
//  Author:           Lingurar Petru-Mugurel
//  Written:          05 Sep 2015  21:04:56
//  Last updated:           ---
//
//
//  Description:
//    ----
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


#include "stdafx.h"

#include "Human.h"


Human::Human(std::string n, int e, int l, double s, bool a)
    : Mammals(n, e, l, s), civilized(a)
{
    std::cout << "\nA human emerged";
}


void Human::talk()
{
    std::cout << "\nBla bla... bla";
}


void Human::walk()
{
    std::cout << "\nLeft-right, left-right at the speed of " << speed;
}


void Human::attack()
{
    if (civilized)
        std::cout << "\nWhy would a human attack another?\n\tJe refuse!";
    else
        std::cout << "\nA human attacks another.";
}


Human::~Human()
{
    std::cout << "\nA human has died.";
}


std::ostream& operator<<(std::ostream &os, const Human &human)
{
    return os << human.name << " lives for around " << human.life_expectancy;
}