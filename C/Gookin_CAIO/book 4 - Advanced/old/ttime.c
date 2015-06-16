#include <stdio.h>
#include <time.h>

void ttime_1(void);
void ttime_2(void);

int main()
{
    ttime_2();

    return 0;
}

void ttime_1(void)
{
    struct tm *t;       //!am declarat o variabila - pointer pentru struct tm(declarata iun time.h)
    time_t now;         //!am declarat o variabila de tipul time_h

    time(&now);
//!sau now = (time)NULL;    //! get the current time
    t = localtime(&now);    //!get the tm structure

    printf("It is now %d:%02d:%02d\n",
           t->tm_hour,
           t->tm_min,
           t->tm_sec);
}

void ttime_2(void)
{
    struct tm *t;
    time_t now;

    time(&now);
    t = localtime(&now);

    if(t->tm_hour >= 12)
    {
    printf("It is now %d:%02d:%02d %s",
           t->tm_hour - 12,
           t->tm_min,
           t->tm_sec,
           "PM"
           );
    }
    else
    {
    printf("It is now %d:%02d:%02d %s",
           t->tm_hour,
           t->tm_min,
           t->tm_sec,
           "AM"
           );
    }
}
