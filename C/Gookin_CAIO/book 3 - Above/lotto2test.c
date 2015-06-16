#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERE 6
#define DIN 49

int main()
{
    int nr;
    int r[NUMERE];    //!Un array r cu 6 spatii

    puts("\t\t\tLoteria fantastica\n\n");

    puts("\t\tExtragere direct in direct\n\n");

    printf("Apasa balamuc pentru a incepe %c %c" , 1, 10);
    getchar();


    srand((unsigned)time(NULL));

    for(nr=0; nr<NUMERE; nr++)
    {
        r[nr] = rand() % DIN+1;

        if(nr==0)
            printf("Primul numar este %d.\n\n", r[nr]);
        else
            printf("Al %dlea numar este %d.\n\n", nr+2, r[nr]);
    }

        printf("Numerele extrase in aceasta seara sunt %c\n\t" , 31);
        for(nr=0; nr<6; nr++)
            printf("%d, " , r[nr]);
 //       printf("\n////\tAl treilea numar extras este %d" , r[3]);
        printf("\n\n\n\r");

        return 0;
    }
