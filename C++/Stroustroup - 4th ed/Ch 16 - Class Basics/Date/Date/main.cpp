//
//  Author:           Lingurar Petru-Mugurel
//  Written:          30 Aug 2015  19:00:15
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



#include <iostream>
#include <string>

#include "Chrono.h"


int main()
{
    std::cout << "\nPlease enter a date: -> ";

    Chrono::Date user_date;
    std::cin >> user_date;

    std::cout << "\nCool!\nSo you've entered\n\t";
    std::cout << user_date;

}