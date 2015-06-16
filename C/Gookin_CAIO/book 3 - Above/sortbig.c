#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int main()
{
    int r[SIZE];     //! integerul r are size spatii
    int c, a, b, temp;

    srand ((unsigned)time(NULL));

    puts("Here is the array unsorted:");
    for(c=0; c<SIZE; c++)
    {
        r[c] = rand() % 100 + 1;    //! r in functie de c = random modul de 100+1(1-100)
        printf("%3d\t" , r[c]);
    }
    putchar('\n');

    /*sort the array*/

    for(a=0; a<SIZE-1; a++)
    for(b=a+1; b<SIZE; b++)
    if(r[a] > r[b])     //! daca SIZE caractere din a sunt mai mari decat SIZE caractere din b
    {
        temp = r[b];
        printf(" temp, r[b], %d / %d\n" , temp, r[b]);
        r[b] = r[a];
        printf("r[b] , r[a] , %d / %d\n" , r[b] , r[a]);
        r[a] = temp;
        printf("r[a] , temp , %d / %d\n" , r[a] , temp);


    }

    /*display*/

    printf("Press Enter to see the sorted array:");
    getchar();

    for(c=0;c<SIZE; c++)
        printf("%3d\t" , r[c]);
    putchar('\n');

    return 0;
}
