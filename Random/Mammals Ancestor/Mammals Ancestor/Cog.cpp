//
//  Author:           Lingurar Petru-Mugurel
//  Written:          06 Sep 2015  13:59:49
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

#include "Cog.h"

Cog::Cog(std::string n, int e, int l, double s) : Mammals(n, e, l, s)
{
    std::cout << "\nA strange new mammal emerged."
              << "\n\tit will be called... " << name;
}


void Cog::talk()
{
    std::cout << "\nMiah, miham.";
}


void Cog::walk()
{
    std::cout << "\n3 paws right, 3 paws left";
}


Cog::~Cog()
{
    std::cout << "\n... And " << name << " died before " << life_expectancy << '.';
}
