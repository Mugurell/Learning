// 
//   Author:           Lingurar Petru-Mugurel
//   Written:          2015-09-05 08:54 PM
//   Last updated:           ---
// 
//   Description:
//     ----
// 
//   Bugs:
//     --- None ---
// 
//   TODO:
//     --- None --- 
// 
//   Notes:
//     --- 
// 
// 



#pragma once

#include "stdafx.h"



class Mammals
{
protected:
    std::string name;
    int         life_expectancy;
    int         legsNo;
    double      speed;
    static std::initializer_list<std::string> common_organs;

public:
    Mammals() = default;
    Mammals(std::string n, int e, int l, double s);

    // common functions for all animals
    void breath();      // breathing through lungs - common to all mammals
    static void print_organs();

    // each mammal has it's own language
    virtual void talk();

    // each mammal has it's own walk; pure virtual => required to override
    virtual void walk() = 0;

    virtual ~Mammals();
};
