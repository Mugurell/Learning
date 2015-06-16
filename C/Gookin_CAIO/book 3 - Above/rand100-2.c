#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 100

int main()
{
    int r[COUNT];   //!Adica integer-ul r are COUNT locuri = 100
    //!Putea la fel de bine sa scrie int r[100] - 100 de integers
    int c;

    srand((unsigned)time(NULL));

    // initialize the array

    for(c=0 ; c<COUNT; c++)
        r[c] = rand () % 100 + 1;

    //display the array

    puts("100 random numbers:");
    for(c=0; c<COUNT; c++)
        printf("%d\t" , r[c]);
    putchar ('\n');

    //reinitialize the array

    for(c=0; c<COUNT; c++)
        r[c] = rand() % 100 +1;

    //display the array again

    puts("\nAnother 100 random numbers:");
    for(c=0; c<COUNT; c++)
        printf("%d\t" , r[c]);
    putchar('\n');

    return 0;
}
