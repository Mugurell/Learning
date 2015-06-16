#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define CATE

int main()
{
    int numere;

    int seed;

    printf("Ai castigat vreodata la loto?\n");
    scanf("%d" , &seed);
    printf("Hai sa vedem ce numere ies acum...\n");

  //  srand(seed);

    for(CATE = 0; CATE <= 5; CATE++)
    {
        srand (time(0));
        printf("Primu%d numar este %d\n", CATE , rand());
        scanf("%d" , &1st);

        if("%d != %d " ,1st );
        printf("Al %dlea numar este %d" , CATE, numere);

    }

    return(0);
}
