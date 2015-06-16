#include <stdio.h>

int main()
{
    char yours [25];
    char mine [25];
    char x;

    printf("What is your name? ");
    gets(yours);
//    strcpy(mine, yours);

    while(mine[x]=yours[x])
        x++;

    printf("My name is %s, just like your name is %s\n\n\n", mine, yours);

    return 0;
}
