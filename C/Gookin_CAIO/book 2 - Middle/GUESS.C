#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 1000
#define TRIES 6

int main()
{
    int guess, number;
    int tries = 1;

    srand((unsigned)time(NULL));

    puts("\tJoaca dea ghicitul\n\n\n");

    number = rand() % RANGE + 1;    /*value from 1 to RANGE
                                    altfel era 0-999*/

    printf("Ma gandesc la un numar de la 1 la %d..\n" , RANGE);
    printf("\tPoti sa ghicesti la ce numar ma gandesc?\n\n\n");

    while(1)
    {
        printf("\nIa zii un numar: ");
        scanf("%d" , &guess);
        if(guess == number)     //! == se foloseste pentru comparatii
                                //! = se foloseste in operatiuni matematice
        {
            printf("\n\n\tBravo!!!!!!!\n\t\tAi ghicit!!!!");
            break;
        }
        else if(guess<number)
            puts("Nup, mai mult ;-)");
        else
            puts("Mai putin ;-)");
        tries++;
        if (tries > TRIES)
            break;
    }
    printf("\n\tNumarul era %d\n\n\n" , number);
    return 0;
}
