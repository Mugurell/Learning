#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 100

int main()
{
    int r[COUNT];
    int c;

    srand ((unsigned)time(NULL));

    for(c=0; c<COUNT; c++)
        r[c] = rand () % 100 +1;
        //! r ia valori din COUNT in functie de c

    puts("100 random numbers\n\n");

    for(c=0; c<COUNT; c++)
        printf("%d\t" , r[c]);
        //! c e 0-100 => se printeaza de 100 de ori r[c] adica rand() % 100 +1

    putchar ('\n');

    return 0;
}
