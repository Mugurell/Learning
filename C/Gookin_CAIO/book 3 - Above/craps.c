#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int throw (void);

//void stelute (void);

//int len;


int main()
{
    int /*x, len,*/ bet, roll, point;
    char c;
 //   char rolling [] = "Rolling the, bones";
//   len = strlen (rolling);

    srand ((unsigned)time(NULL));

    printf("Enter your bet: $");
    scanf("%d" , &bet);
    putchar('\n');
    putchar('\n');

    puts("Rolling them bones...!");
    roll = throw();

    printf("\n%d\n\n" , roll);
    switch(roll)
    {
    case 7:
    case 11:
        printf("- You win!\n");
        bet *=2;     //!bet = bet x 2
        break;
    case 2:
    case 3:
    case 12:
        printf("- Craps! You loose!\n");
        bet = 0;
        break;
    default:
        point = roll;
        printf("- Your point is now %d\n" , point);
        while(1)   //!while true - infinite loop pana ii dai false/break
        {
            roll = throw();
            printf("\tYou rolled %d, point is %d.\n", roll , point);
            if(roll==point)
            {
                printf("\tYou win!\n");
                bet*=2;
                break;
            }
            if(roll==7)
            {
                printf("\tSeven out, you loose!\n");
                bet = 0;
                break;
            }
        }
    }

    printf("\n\nYou have now $%d.\n", bet);

    return 0;
}

/*void stelute(void)
{
    int x=0;
    for(x=0; x=20; x++)
        printf(".");
        x=0;
    for(x=0; x<10; x++)
        putchar(' ');
        x=0;
    for(x=0; x=len; x++)
        putchar('*');
    }
*/

int throw (void)
{
    int die1, die2, total;

    die1 = rand() % 6+1;
    die2 = rand() % 6+1;
    total = die1+die2;
    return(total);
}
