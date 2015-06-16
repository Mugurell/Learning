#include <stdio.h>
#include <ctype.h>

char ask(void);

int main()
{
    char key;

    printf("Would you like me to send you to the menu?");
    key = ask();        //!char ask(void) se stocheaza in variabila key

    if(key == 'Y')
    {
    printf("\n\n\tWell.. Someday a menu will appear here... %c" , 1);
    /*finish this later*/
    }

    return 0;
}

char ask (void)
{
    char c;
    printf("\n\nJust say it man, Yes or No? %c" , 16);
    fflush(stdin);
    c = toupper(getchar());
    if(c == 'Y')
        return(c);
    else
        return ('N');
}
