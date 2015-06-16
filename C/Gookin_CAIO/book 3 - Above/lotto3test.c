#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERE 6
#define DIN 49


int main()
{
    int c, nr;
    int numere[DIN];

    puts("\t\t\tLoteria fantastica\n\n");

    puts("\t\tExtragere direct in direct\n\n");

    printf("Apasa balamuc pentru a incepe %c %c" , 1, 10);
    getchar();


    srand((unsigned)time(NULL));

    for(c=0; c<DIN; c++)
        numere[c]=0;     //!A initializat toate DIN(49) numere la 0

    for(c=0; c<NUMERE; c++)
    {
        do
        {
            nr=rand() % DIN+1;
        }while(numere[nr]);
//! While-ul asta e cheia!!
//! Asta

        numere[nr] = 1;
        printf("%2d " , nr);

        /*
               if(nr==0)
                   printf("Primul numar este %d.\n\n", r[0]);
               else
                   printf("Al %dlea numar este %d.\n\n", nr+1, r[nr]);
           }

               printf("Numerele extrase in aceasta seara sunt %c\n\t" , 31);

               for(nr=0; nr<6; nr++)
                   printf("%d, " , r[nr]);
        //       printf("\n////\tAl treilea numar extras este %d" , r[0]);
               printf("\n\n\n\r");
        */
    }
    return 0;
}

