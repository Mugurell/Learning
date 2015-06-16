#include <stdio.h>

int main()
{
    char phrase[] = "sushi is mooshi";
    char ch;
    int x = 0;

//! Ia cate un caracter pe rand, atat timp cat nu e '\0' adica NULL

    /*   do
       {
           ch = phrase[x];
           putchar(ch);
           x++;
       }while (ch != '\0');
    */

    while(ch = phrase[x])
    {
        putchar(ch);
        x++;
    }

    putchar ('\n');

//!A 3-a variatiune
    phrase[9] = 'F';
    puts(phrase);
    phrase[5]='-';
    phrase[8]='-';
    puts(phrase);

/*
//!A 4-a variatiune
    do
    {
        ch=phrase[x];
        x++;
        if(x=='m')
            puts('K');
        else
        putchar(ch);
    }
    while (ch != '0');


//!A 5-a variatiune
    while(ch=phrase[x])
        if(x=='m')
            puts('K');
        else
    putchar(ch);
    x++;
*/

    return 0;
}
