#include <stdio.h>

#define SIZE 6

int main()
{
    int loto[] = {10, 48, 1, 37, 6, 24};
    int c, a, b, temp;

    puts("Here is the array unsorted:*");
    for(c=0; c<SIZE; c++)
        printf("%2d ", loto[c]);    //!C ia valorile din loto
    putchar('\n');

    /*sort the array*/

    for (a=0; a<SIZE; a++)
        for(b=a+1; b<SIZE; b++)
            if(loto[a]>loto[b])
            {
                temp=loto[b];
                loto[b]=loto[a];
                loto[a]=temp;
            }

    /*display the result*/

    puts("Here is the sorted array:");
    for(c=0; c<SIZE; c++)
        printf("%2d ", loto[c]);
    putchar('\n');              //!A folosit exact acceasi sintaxa de la inceput ;-)

    getchar();
    return 0;
}
