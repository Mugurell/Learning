#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 49
#define BALLS 6

int main()
{
    int numbers[RANGE];
    int c, ball;

    puts("\t\t\tLOTTO PICKER\n\n");

    srand((unsigned)time(NULL));

/*initialize the array*/

    for(c=0; c<RANGE; c++)
        numbers[c]=0;     //!A initializat toate RANGE(49) numere la 0

    puts("Press Enter to get this week's numbers:");
    getchar();

/*draw the numbers*/

    puts("Here they come..:");
    for(c=0; c<BALLS; c++)
    {
/*see if a number has already been drawn*/
        do
        {
            ball=rand() % RANGE+1;
        }
        while(numbers[ball]);

/*Number drawn*/

        numbers[ball] = 1;
        printf("%2d " , ball);
    }

    printf("\n\nGood luck in the drawing!\n\n");

    return 0;
}
