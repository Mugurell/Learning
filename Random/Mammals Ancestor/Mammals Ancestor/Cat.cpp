//
//  Author:           Lingurar Petru-Mugurel
//  Written:          05 Sep 2015  21:07:37
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

#include "Cat.h"


Cat::Cat(std::string n, int e, int l , double s)
    : Mammals(n, e, l, s)
{
    std::cout << "\nA cat appeared at our doorstep.";

}


void Cat::walk()
{
    std::cout << "\nLeft front paw & back right paw, right front paw &"
              << "back left paw..at the speed of " << speed;
}


void Cat::talk()
{
    std::cout << "\nNyan cat theme song!";
}


Cat::~Cat()
{
    std::cout << '\n' << name << " isn't moving.";
}
