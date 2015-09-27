//
//  Author:           Lingurar Petru-Mugurel
//  Written:          05 Sep 2015  21:05:08
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

#include "Dog.h"


Dog::Dog(std::string n, int e, int l, double s)
    : Mammals(n, e, l, s)
{
    std::cout << "\nGood doggie!";
}


void Dog::talk()
{
    std::cout << "\nMrr Ham Ham! Ham!";
}


void Dog::walk()
{
    std::cout << "\nLeft front paw & back right paw, right front paw &"
              << "back left paw..at the speed of " << speed;
}


Dog::~Dog()
{
    std::cout << '\n' << name << " was my best friend...";
}


std::ostream& operator<<(std::ostream &os, const Dog &dog)
{
    return os << dog.name << " lives for around " << dog.life_expectancy;
}