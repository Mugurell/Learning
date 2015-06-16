#include <stdio.h>
#include <stdio.h>

int main()
{
    char dwarf[7][2][8] =
//!7 stringuri pe 2 coloane cu 7 caractere {al optulea e NULL ;-) )
    {
        "bashful", "?",
        "doc","?",
        "dopey","?",
        "grumpy","?",
        "happy","?",
        "sneezy","?",
        "sleepy","?",
    };
    char input [64];
    int named = 0;
    int x;

    puts("\t----------\nSee if you can name all 7 dwarfs\n\t----------\n\n");

    while(named<7)
    {
        if(named==1)
            printf("\nSo far you've named %d dwarf\n", named);
        else
            printf("\nSo far you've named %d dwarfs\n", named);
        printf("Enter a name:");
        gets(input);

//!check for no input
        if(strcmp(input, " ")==0) //daca 0/1 == 0
            break;

        for(x=0; x<7; x++)
        {
            if(strcmpi(input,dwarf[x][0])==0)  //daca 0/1 == 0
                                                //daca input e vreunul din nume
//!strcmpi e acelasi lucru cu strcacmp
            {
                if (dwarf[x][1][0] =='!')
                    printf("\tYou allready named that dwarf!!!%c\n", 1);
                else
                {
                    printf("Yes! %s is one of them!\n\n", input);
                    named++;
                    dwarf[x][1][0]='!';
                }
            }
        }

        if(named==7)
            printf("\n\tWOW, You know them all!!! :-O\n");
        else
            puts("Try again:");
    }
    return 0;
}
