#include <stdio.h>
#include <string.h>

int main()
{

    char input [64];
    int size, c;

    printf("Enter a common earthly phrase please: -> ");
    gets(input);

    puts("Here is how we say that on Backward Planet:");
    size = strlen(input);

    for(c=size-1; c>=0; c--)
    putchar(input[c]);
//!plecand de la size-1, pana la c>=0 , scazand cu o unitate incontinuu
//!Afiseaza caracterul din input in functie de c input[c]

    putchar('\n');
    return 0;
}
