//
//  Author:           Lingurar Petru-Mugurel
//  Written:          05 Sep 2015  20:54:43
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

#include "Mammals.h"


std::initializer_list<std::string>
Mammals::common_organs{ "heart", "liver", "lungs", "uterus" };


void Mammals::print_organs()
{
    std::cout << '\n';
    for (std::string each_organ : common_organs)
        std::cout << each_organ << ' ';
}



Mammals::Mammals(std::string n, int e, int l, double s)
    : name(n), life_expectancy(e), legsNo(l), speed(s)
{
    std::cout << "\nA mammal is born.";
}


void Mammals::breath()
{
    std::cout << "\nBreath in\n\tBreath out.";
}


void Mammals::talk()
{
    std::cout << "\nMumbo jambo babilon";
}


Mammals::~Mammals()
{
    std::cout << "\nA mammal has fallen";
}
