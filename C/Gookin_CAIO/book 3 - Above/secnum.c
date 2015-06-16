#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void separator (int repeat, char c);

int main()
{
    long int r;
    srand((unsigned)time(NULL));

    printf("Here are today's secret number values %c\n" , 31);
    separator(10, '*');      //int repeat=10, char =....
    separator(15, '_');      //int repeat=15
    separator(20, '#');      //int repeat=20

    return 0;
}
void separator (int repeat, char c)
{
    int x;
    long int r;

    for (x=0; x<repeat; x++)
        putchar(c);
    putchar('\n');
    r = rand();
    printf("%d\n" , r);
    return;
}
