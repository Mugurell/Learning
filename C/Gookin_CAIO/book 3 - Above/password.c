#include <stdio.h>
#include <string.h>

int main()
{
    char pswd[] = "please";
    char parola[25];
    int x = 10;
    int result;
    int i;

    puts("Due to some strange keystrokes I believe this computer is hacked");
    printf("I'm gonna call the police now.. %c%c\n\n" , 1, 10);
    do
    {
        printf("\t\t%d\n" , x);
        x--;
    }while (x>=0);

    for(i=0; i<4 ; i++)
    {
        printf("\nYou can stop all this procedure just by enterig the secret password! -> ");
        scanf("%s" , & parola);
        result = strcasecmp (parola, pswd);

/*
//!Test pt a vedea daca stocheaza corect parola
        printf("\n\tParola introdusa este %s\n\n" , parola);
//!Test pentru a vedea strcaasecmp opereaza corect
        printf("\n\tstrcasecmp result e %d\n\n" , result);
*/

        if(result == 0)
        {
            puts("Faith in the operator : restored");
            printf("Have a great day and sorry for all the problems %c\n\n\n" , 9);
            //break;
            goto tambalau;
        }
        else if((result == 1 || result ==-1) && i <=1)
            puts(".....Wrong password");
        else if((result == 1 || result ==-1) && i==2)
        {
            puts(".....Wrong password");
            printf("Allready giving the necessary details top the FBI\n\n");
        }
        else
        {
            puts("The FBI, CIA, NSA & MSA samd are coming..");
            printf("You'd better hide that child pornography stash ;-)\a\n\n\n\n\r");
        }

/*
//!Test pentru a vedea valoarea lui i
        printf("\n\n\tValoarea lui i este %d\n\t--------------------------------------------------------\n\n" , i);
*/
    }
    tambalau:
    getchar();
    return 0;
}
