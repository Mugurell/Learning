#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSE 0
#define TRUE !FALSE
#define OMEGA ('Z' - 'A')      //se scade in ASCII z-a ca sa iti dea rangeul din care sa cauti

int main()
{
    int done , litere=0;
    long int r;
    char alpha;

    srand((unsigned)time(NULL));

    done=FALSE;

    while(!done)       //cat timp nu e fals (!=fals = adevarat)
    {
        r = rand() % OMEGA;     //OMEGA = Z-A (in ascii) = 25
        alpha = 'a' + (char)r;      //incepi sa numeri in ascii peste 'A' => ex A+2=C
        if(alpha=='q') done = TRUE;   //while !done - done e fals. Acum e adevarat.
        putchar(alpha);
        litere++;
    }
        printf("\n\nIn total %d litere\n\n" , litere);
    return 0;
}
