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


#pragma once

#include "Mammals.h"


class Cat : public virtual Mammals
{
public:
    Cat() = default;
    Cat(std::string n, int e, int l, double s);

    void talk() override;
    void walk() override;



    ~Cat() override;
};

