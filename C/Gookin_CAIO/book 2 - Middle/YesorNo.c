#include <stdio.h>

#define FALSE 0
#define TRUE !FALSE

int main()
{
    int done;
    char ch;

    done = FALSE;
    printf("Would you like me to send your password to bad persons?\n");
    while(!done)
    {
        printf("Enter Y or N (Y/N)? : ");
        ch = getchar();

        switch(ch)
        {
        case 'N':
        case 'n':
            printf("Okay, then your password is safe!\n\n");
            done = TRUE;
            break;   //!fara break le lua pe urmatoarele si dupaia se oprea
        case 'Y':
        case 'y':
            printf("Okey.. if you say so...\n\t..Password sent!\n\n");
            done = TRUE;
            break;
        default:
            printf("You must enter Y or N!\a\n\n\v");
            fflush(stdin);      //!fpurge for unix

        } /*end switch*/
    } /*end while*/
    return 0;
}
