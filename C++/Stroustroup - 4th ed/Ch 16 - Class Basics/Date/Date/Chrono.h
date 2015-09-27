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
    // as an enum class, it will not support implicit conversions!
    enum class Month : unsigned short
    {
        Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
    };


    class Date
    {
        friend std::istream& operator>>(std::istream &is, Date &d);
    public:
        class Bad_date {};      // exception class

        // the default obtained will be 0, Jan, 0 - not a valid date
        // used Month::Jan because 0 as a month is undefined,
        // it doesnt exist in the Month enum
        explicit Date(int dd = {}, Month mm = Month::Jan, int yy = {});

    // nonmodifying functions for examining the Date:
        int   day()  const { return d; }
        int month()  const { return m; }
        int  year()  const { return y; }

        std::string string_rep() const;         // string representation
        void char_rep(char *s, int max) const;  // C-style string representation

    // modifying functions for changing the Date
        Date& add_year (int n);
        Date& add_month(int n);
        Date& add_day  (int n);

        static void set_default(int dd, int mm, int yy);

    private:
        bool is_valid();                // check if this Date represents a date
        bool is_leap_year();
        int d, m, y;                    // representation
    };

    std::ostream& operator<<(std::ostream &os, const Date &d);

    bool operator==(const Date &a, const Date &b);
    bool operator!=(const Date &a, const Date &b);

}
