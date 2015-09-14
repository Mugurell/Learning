// 
//   Author:           Lingurar Petru-Mugurel
//   Written:          2015-09-05 09:05 PM
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


#pragma once

#include "Mammals.h"

class Dog : public virtual Mammals
{
    friend std::ostream& operator<<(std::ostream &os, const Dog &dog);

public:
    Dog() = default;
    Dog(std::string n, int e, int l, double s);

    void talk() override;
    void walk() override;

    ~Dog() override;
    
};
