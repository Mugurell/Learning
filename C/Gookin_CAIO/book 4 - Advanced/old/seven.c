#include <stdio.h>
#include <string.h>

void seven_1(void);
void seven_2(void);

int x;

int main()
{
    seven_1();
    printf("\n*******\n\n");
    seven_2();

    return 0;
}

void seven_1(void)
{
    char dwarf[7][8];

    strcpy(dwarf[0], "bashful");
    strcpy(dwarf[1], "doc");
    strcpy(dwarf[2], "dopey");
    strcpy(dwarf[3], "grumpy");
    strcpy(dwarf[4], "happy");
    strcpy(dwarf[5], "sneezy");
    strcpy(dwarf[6], "sleepy");

/*! You have to use the strcpy() function
    to copy a string constant into a
    structure’s string variable!
Asta daca nu ai definit structura bine de la inceput...
*/


    for(x=0; x<7; x++)
        printf("%10s\n" , dwarf[x]);
}

void seven_2(void)
{
    const char *dwarf[] =
    {
        "bashful",
        "doc",
        "dopey",
        "grumpy",
        "happy",
        "sneezy",
        "sleepy"
    };

    for(x=0; x<7; x++)
    {
        printf("%-10s\n" , dwarf[x]);
    }
}
