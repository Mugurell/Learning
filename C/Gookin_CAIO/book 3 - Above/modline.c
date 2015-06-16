#include <stdio.h>
#include <string.h>
#include <ctype.h>

void showline(void);
void dashes(char c);
void shout (void);

/* 2 global variables*/
char line [50];    //!80 de caractere inafara de \0
int linelen;     //!line lenght, initializata la 0

int main()
{
    int x=0;

    printf("Enter a line of text %c\n" , 25);
    gets(line);
    linelen = strlen(line);     //!returns the lenght of a string minus the null character

/*
    int x=0;

        do
    {
        line[x] = toupper(line[x]);
        x++;
    }while(line[x]);
*/

    printf("\n\nHere is the line you've just entered %c\n\n" , 31);
    shout();

    getchar();

    return 0;
}

void shout (void)
{
    int x=0;

    dashes('*');
    do
    {
        putchar(toupper(line[x]));        //! pune cate o litera din toupper(line)
        x++;
    }while(line[x]);
    putchar('\n');
    dashes('#');
}

void showline(void)
{
    dashes(' ');
    puts(line);
    dashes('*');
}

void dashes(char c)
{
    int x;
    if(c==' ')
    {
        putchar('\n');
        return;             //!iese mai inainte din functie
    }
    for(x=0; x<linelen; x++)
        putchar(c);
    putchar('\n');
}


