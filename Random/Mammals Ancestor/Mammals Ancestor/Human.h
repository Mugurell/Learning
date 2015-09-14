// 
//   Author:           Lingurar Petru-Mugurel
//   Written:          2015-09-05 09:04 PM
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

class Human : public Mammals
{
    friend std::ostream& operator<<(std::ostream &os, const Human &human);

private:
    bool civilized;

public:
    Human() = default;
    Human(std::string, int, int, double, bool);

    void talk() override;
    void walk() override;

    void attack();

    ~Human() override;
};
