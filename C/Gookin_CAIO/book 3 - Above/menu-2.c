#include <stdio.h>
#include <ctype.h>

char ask(void);

int main()
{
    char key;

    printf("Would you like me to send you to the menu?");
    key = ask();        //!char ask(void) se stocheaza in variabila key
                        //! key oi sa fie Y/N

    if(key == 'Y') return 0;


    printf("Would you really like to see the menu? %c\n\n" , 1);
    key = ask();
    if(key == 'Y')
    {
        puts("Someday the menu will appear here...");

    /*finish this later*/
    }

    return 0;
}

char ask (void)
{
    char c;
    printf("\n\nJust say it man, Yes or No? %c " , 16);
    fflush(stdin);
    c = toupper(getchar());
    while(getchar() != '\n')
        continue;
    printf("\n\n");
    if(c == 'Y')
        return(c);
    else
        return ('N');
}
