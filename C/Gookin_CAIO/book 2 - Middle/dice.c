#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLLS 1000

int main()
{
    int d1, d2, loop;
    int td1 = 0;
    int td2 = 0;
    float ad1, ad2;
    int running_total = 0;

    td1=0;

    srand((unsigned)time(NULL));

    for(loop=0; loop<ROLLS; loop++)
    {
        d1=rand()%6 +1;
        d2=rand()%6 +1;
        printf("You rolled %d and %d\n" , d1 , d2);
        td1=td1+d1;
        td2+=d2;    //td2 =td2 = d2
    }
    printf("//%d d1\n" , td1);
    printf("//%d d2\n\n\n" , td2);

    ad1 = (float)td1/ ROLLS;
    ad2 = (float)td2/ ROLLS;
    printf("The average roll for %d times was %.2f/%.2f\n" , ROLLS , ad1, ad2);
    return 0;
}
