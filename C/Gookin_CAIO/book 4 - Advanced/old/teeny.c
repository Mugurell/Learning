#include <stdio.h>

int main()
{
    float teeny;
    float *t;

/*initialize variables*/
    teeny = 1.414213;
    t = &teeny;

/*use and abuse variables*/
    printf("Variable teeny = %f\n" , teeny);
    printf("Variable t = %p\n" , t);
    printf("Variable *t = %f\n" , *t);

    *t = 64;
    putchar('\n');
    printf("Variable teeny = %f\n" , teeny);
    printf("Variable t = %p\n" , t);
    printf("Variable *t = %f\n" , *t);

    exit (437364);
}
