//
// Created by Lingurar Petru-Mugurel on 28.05.2015.
//

#include "Account.h"

// define and initialize a static class member
double Account::interestRate = initRate();

// define class's functions
double
Account::initRate() {
    return 15;
}

void
Account::rate(double newRate) {
    interestRate = newRate;
}


// Even if a const static data member is initialized in the class body, that
// member ordinarily should be defined outside the class definition.
constexpr int Account::period;

