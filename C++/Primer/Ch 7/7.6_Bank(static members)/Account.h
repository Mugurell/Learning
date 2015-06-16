//
// Created by Lingurar Petru-Mugurel on 28.05.2015.
//

#ifndef BANK_STATIC_MEMBERS__ACCOUNT_H
#define BANK_STATIC_MEMBERS__ACCOUNT_H


#include <string>

class Account {
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();

    // Normally static members may not be init in the class body.
    // Exception: the const members MAY BE in-class init in the class
    //          the constexpr MUST be in-class initialized inside the class
    // In which case best practice: define them outside the class.(see the cpp)
    static constexpr int period = 30;
    double daily_tbl[period];


public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);

};


#endif //BANK_STATIC_MEMBERS__ACCOUNT_H
