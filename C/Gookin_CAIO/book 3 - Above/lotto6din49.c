#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERE 6
#define DIN 49


int main()
{
    int nr, unu, temp;
    int r[NUMERE-1];    //!Un array r cu 6 spatii

    puts("\t\t\tLotoria fantastica\n\n");

    puts("\t\tExtragere direct in direct\n\n");

    printf("Apasa balamuc pentru a incepe %c %c" , 1, 10);
    getchar();


    srand((unsigned)time(NULL));

    unu = rand() % DIN+1;
    printf("..\n\t..\n\t\t..\n\nPrimul numar este %d.\n\n" , unu);

/*! Ai putea sa-i bagi un if(rand = r[]) continue
ca sa ia loopul de la inceput, un nou rand
v pg 232*/


    for(nr=0; nr<NUMERE-1; nr++)
    {
        r[nr] = rand() % DIN+1;

        printf("Al %dlea numar este %d.\n\n", nr+2, r[nr]);
    }
    printf("Numerele extrase in aceasta seara sunt %c\n\t %d, " , 31, unu );
    for(nr=0; nr<5; nr++)
        printf("%d, " , r[nr]);
    printf("////\tAl treilea numar extras este %d" , r[0]);
    printf("\n\n\n\r");

    return 0;
}
