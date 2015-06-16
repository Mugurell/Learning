#include <stdio.h>
#include <ctype.h>

#define FALSE 0
#define TRUE !FALSE

int main()
{
    int x, done;
    char ch;

    done=FALSE;
    printf("Would you like me to send your password to the bad guys?\n");
    while(!done)
    {
        printf("\nEnter Y or N (Y/N) %c " , 16);
        ch = tolower(getchar());
        switch(ch)
        {
        case 'n':
            printf("\nWell, then your password is safe...\n\t... for now %c\n\n\n" , 1);
            done = TRUE;
            break;
        case 'y':
        {
            printf("\nSending your password to the bad guys... %c" , 2);
            for(x=10; x>=1; x--)
            {
                printf("\n\t..%2d..." , x);
            }
            putchar ('\n');
            putchar('\n');
            printf("Your beloved %c password is now at the mercy of the bad guys... \n\t..ready to be abused... %c%c%c\n\t\t..repeteadly %c\n\n\n\n" , 3, 16, 18, 17, 1);
            done = TRUE;
            break;
        }
        default:
            printf("\nYou must enter Y or N !!!");
            fflush(stdin);
        }
    }
    fflush(stdin);
    getchar();
    return 0;

}
