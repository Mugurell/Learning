#include <stdio.h>

int main(int argc, char* argv[])
{
    int x;

    printf("There were %d arguments\n", argc);

    for (x = 0; x < argc; x++)
        printf("#%d : %s\n", x, *(argv + x));

    return 0;
}