#include <stdio.h>

void thing_1(void);
void thing_2(void);

int main()
{
    thing_2();

    return 0;
}

void thing_1(void)
{
    char *hello = "Greetings from your computer!";
    char bye_bye[] = "So long now!";
    char *b;

/*initialize the pointer*/
    b = bye_bye;

    puts(hello);
    puts(b);
}

void thing_2(void)
{
    const char *hello = "Greetings from your computer!";
    char bye_bye[] = "So long now!";
    char *b;

/*initialize the pointer*/
    b = bye_bye;

    while(*hello)
        puts(hello++);
}
