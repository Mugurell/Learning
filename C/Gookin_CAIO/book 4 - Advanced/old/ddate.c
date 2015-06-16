#include <stdio.h>
#include <time.h>

void ddate_1(void);
void ddate_2(void);

int main()
{
    ddate_2();

    return 0;
}

void ddate_1(void)
{
    struct tm *t;
    time_t now;

    time(&now);
    t = localtime(&now);

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

    printf("%02d/%02d/%d\n\n\n",
           t->tm_mon+1,
           t->tm_mday,
           t->tm_year-101);
}

void ddate_2(void)
{
    char *zile [] = {
        "Duminica",
        "Luni",
        "Marti",        //!un array de caractere
        "Miercuri",
        "Joi",
        "Vineri",
        "Sambata"};




    struct tm *t;
    time_t now;

    time(&now);
    t = localtime(&now);

    printf("Astazi e %s, %02d/%02d/%d\n\t",
           zile[t->tm_wday],
           t->tm_mday,
           t->tm_mon+1,
           t->tm_year+1900);
    if(t->tm_hour >=12)
        printf("iar ceasul este %2d:%02d:%02d %s.\n\n",
               t->tm_hour-12,
               t->tm_min,
               t->tm_sec,
               "PM");
    else
        printf("iar ceasul este %2d:%02d:%02d %s.\n\n",
               t->tm_hour,
               t->tm_min,
               t->tm_sec,
               "AM");
}



