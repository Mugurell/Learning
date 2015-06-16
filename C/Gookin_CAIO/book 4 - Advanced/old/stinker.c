#include <stdio.h>

void stink_1(void);
void stink_2(void);
void stink_3 (void);
void get_name (void);

int main()
{
    get_name();

    return 0;
}

void stink_1(void)
{
    char string[] = "Is it supposed to smell that way?";
    char ch;
    int x;

    /*initialize variables*/
    ch ='a';
    x = 0;

    while (ch != '\0')
    {
        ch  = string [x++];
        putchar (ch);
    }

}

void stink_2(void)
{
    char string[] = "Is is supposed to smell that way?";
    char *s;

    /*initialize the array*/
    s = string;

    while(*s)
    {
        putchar(*s++);
    }
}

void stink_3(void)
{
    char string[] = "Is it supposed to smell like this..?";
    char *s = string;

    while(putchar(*s++));
}

void get_name (void)
{
    char nume [20];

    printf("What's your name? %c ", 16);
    gets(nume);

    char *n = nume;

    while(putchar(*n++));

}
