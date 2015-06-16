#include <stdio.h>
#define CATE 100

int main()
{
    int numere[CATE];
    int al;
    int a, b, temp;

    srand((unsigned)time(NULL));

    printf("%d de numere aleatorii %c %c:\n\n", CATE, 1, );

//! loop pentru a afla CATE de numere aleatorii
    for(al=0; al<=CATE; al++)
    {
        numere[al] = rand() % 100;
        printf("%d\t" , numere[al]);
    }

//! bubble_sort
    for(a=0; a<CATE-1; a++)
        for(b=a+1; b<CATE; b++)
            if(numere[a]>numere[b])
            {
                temp   = numere[b];
                numere[b] = numere[a];
                numere[a] = temp;
            }
//!numerele sortate
    printf("\n\nApasa balamuc pentru a sorta numerele %c%c%c\n\n " ,1, 9774, 31);
    getchar();
    for(al=0 ; al<CATE; al++)
        printf("%d\t" , numere[al]);
    putchar('\n');


    return 0;


}
