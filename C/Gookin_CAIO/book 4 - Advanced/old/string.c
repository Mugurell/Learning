#include <stdio.h>

void string_1(void);
void string_2(void);

int main()
{
    string_2();

    return 0;
}

void string_1(void)
{
    char text [] = "Going! Going! Gone!";
    char *t;

/*initialize the pointer*/
    t = text;

/*display the string*/
    puts(t);
}

void string_2(void)
{
    char text [] = "Going! Going! Gone!";
    char *t;

/*initialize the pointer*/
    t = text;

/*display the string*/
    while(*t)
        puts(t++);
}

