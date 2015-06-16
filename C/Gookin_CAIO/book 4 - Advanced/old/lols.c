#include <stdio.h>

int main()
{
    int start, finish;
    int *examine;

    start = 100;
    finish = 9;

    examine = &start;
    *examine = 100;

    printf("%d little old ladies started the race.\n" , start);
    examine = &finish;
    printf("But only %d little old ladies finished.\n" , *examine);
    printf("");

    exit(3245);
}
