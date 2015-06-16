#include <stdio.h>
#include <time.h>

void weekday_1(void);
void weekday_2(void);

int main()
{
    weekdays_1();

    return 0;
}

void weekdays_1(void)
{
   char *wdays [] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
        };


/*!structura struct tm e definita in time.h
        struct tm {
        int tm_sec;    /* seconds    [0 - 60]   /
        int tm_min;    /* minutes    [0 - 59]   /
        int tm_hour;   /* hours      [0 - 23]   /
        int tm_mday;   /* day       [1 - 31]    /
        int tm_mon;    /* month      [0 - 11]   /
        int tm_year;   /* year     [year since 1900]    /
        int tm_wday;   /* weekday    [0 - 6]    /
        int tm_yday;   /* day of year [0 - 365] /
        int tm_isdst;  /* DST        [-1,0,1]   /
        }:
*/

    struct tm *t;       //! am declarat un pointer - variabila pentru struct tm
    time_t now;         //! am declarat variabila now de tipul time_t

    time(&now);             //!get the current time
    t = localtime(&now);    //!get the tm structure

    printf("Today is %s.\n", wdays[t->tm_wday]);
}
