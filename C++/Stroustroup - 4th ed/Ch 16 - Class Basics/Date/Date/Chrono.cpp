//
//  Author:           Lingurar Petru-Mugurel
//  Written:          30 Aug 2015  18:59:13
//  Last updated:           ---
//
//
//  Description:
//    Implementation file for the objects in the Chrono namespace.
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


#include "Chrono.h"


Chrono::Date::Date(int dd, Month mm, int yy)
    : d(dd), m(static_cast<int>(mm)), y(yy)
{
    // make sure we have a valid date
    is_valid();
}


std::istream& Chrono::operator>>(std::istream &is, Date &d)
{
    return is >> d.d >> d.m >> d.y;
}

std::ostream& Chrono::operator<<(std::ostream &os, const Date &d)
{
    return os << d.day() << '-' << d.month() << '-' << d.year();
}


bool Chrono::Date::is_leap_year()
{
    bool is_leap;

    // if not evenly divisible by for, it is NOT a leap year
    if (y % 4 == 0)
    {
        // if divisible by 4, but not 100, like 2012, it is a leap year
        if (y % 100 != 0)
            is_leap = true;

       // if divisible by 100, but not 400, like 1900, it is NOT a leap year
        else if (y % 400 != 0)   // 
            return is_leap = false;
    }
    else
        is_leap = false;

    return is_leap;
}

bool Chrono::Date::is_valid()
{
    bool is_valid = false;

    // february has 28 days in a leap_year
    if (!is_leap_year() && m == 2 && d > 28)
        std::cerr << "Invalid date: 29 February only possible in a leap year";

    // february has 29 days in a leap_year
    else if (is_leap_year() && m == 2 && d > 29)
        std::cerr << "Invalid day number: Only [1 - 29] allowed";

    // jan, mar, may, july, aug, oct, dec have 31 days
    else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10
        || m == 12) && (d > 31))
        std::cerr << "Invalid day number: Only [1 - 31] allowed";

    // apr, june, sep, nov have 30 days
    else if ((m == 4 || m == 6 || m == 9 || m == 11) && (d > 30))
        std::cerr << "Invalid day number: Only [1 - 30] allowed";

    // if all checks passed means we have a valid date
    else
        is_valid = true;

    return is_valid;
}