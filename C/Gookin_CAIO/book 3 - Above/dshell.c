#include <stdio.h>
#include <string.h>

void showprompt(void);              /*prototype*/

int main()
{
    char input [64];

    do
    {
        showprompt();       /*call the function*/
        gets(input);
        puts("Someday I must implement that function..");
    }
    while((strcasecmp)("quit" , input));
/*  while 1
    `strcasecmp returneaza 0 atunci cand elementele sunt identice
        (fara a tine cont de majuscule)
*/
    puts("Oh! Apparently I did!");


    return 0;
}

void showprompt(void)
{
    printf("What is thy bidding?");
}
