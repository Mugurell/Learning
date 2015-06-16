#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int bet, roll, point;
    char c;

    srand((unsigned)time(NULL));

    printf("Enter your bet: ");
    scanf("%d" , & bet);

    puts("\n\tRolling them bones...\n");
    roll = rand() %11+2;     //Ai 2 zaruri, deci minim poti sa dai 1-1 adica 2 ;-)

    printf("\t\t\t%d\n\n" , roll);
    switch (roll)
    {
    case 7:
    case 11:
        printf(" - You win!\n");
        bet *=2;     //! bet = bet x 2
        break;

    case 2:
    case 3:
    case 12:
        printf(" - Craps! You lose!\n");
        bet = 0;
        break;
    default:
        point = roll;
        printf(" - Your point is now %d.\n" , point);
        while(1)    //! asta e un infinite loop, la fel ca for(::)
        {
            roll = rand() % 11+2;
            printf("\tYou rolled %d, point is %d.\n" , roll, point);
            if(roll==point)
            {
                printf("\tYou win!\n");
                bet *=2;
                break;
            }
            if(roll==7)   //! = folosesti doar la operatiile matematice!
            {
                printf("\tSeven out, you lose");
                bet = 0;
                break;
            }
        }
    }
    printf("\n\n\tYou now have $%d." , bet);
    return 0;
}
