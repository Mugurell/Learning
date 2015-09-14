//
//  Author:           Lingurar Petru-Mugurel
//  Written:          30 Aug 2015  18:59:13
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

#include <iostream>
#include <string>


namespace Chrono
{
    enum class Month : unsigned short
    {
        Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
    };


    class Date
    {
    public:
        class Bad_date {};      // exception class

        // the default obtained will be 0, 0, 0 - not a valid date
        explicit Date(int dd = {}, Month mm = {}, int yy = {});

    // nonmodifying functions for examining the Date:
        int   day()   const;
        Month month() const;
        int   year()  const;

        std::string string_rep() const;         // string representation
        void char_rep(char *s, int max) const;  // C-style string representation

    // modifying functions for changing the Date
        Date& add_year (int n);
        Date& add_month(int n);
        Date& add_day  (int n);

    private:
        bool is_valid();    // check if this Date represents a date
        int d, m, y;        // representation
    };

    bool is_date(int d, Month m, int y);    // true for valid date
    bool is_leapyear(int y);                

    bool operator==(const Date &a, const Date &b);
    bool operator!=(const Date &a, const Date &b);

    const Date& default_date();     // the default date

    std::ostream& operator<<(std::ostream &os, const Date &d);
    std::istream& operator>>(std::istream &is, const Date &d);

}
