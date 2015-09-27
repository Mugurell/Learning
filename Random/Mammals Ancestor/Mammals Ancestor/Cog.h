// 
//   Author:           Lingurar Petru-Mugurel
//   Written:          2015-09-06 01:59 PM
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
//     Probably a mule would fit better
// 


#pragma once

#include "stdafx.h"
#include "Dog.h"
#include "Cat.h"


class Cog
    : public Dog,
      public Cat        // don't ask me why
{
public:
    // Cog() = default;
    Cog(std::string n, int e, int l, double s);
    
    void talk() override;
    void walk() override;

    ~Cog();
};
