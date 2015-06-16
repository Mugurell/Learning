#include <stdio.h>

int main()
{
    char c;
    short int i;
    long x;
    float f;
    double d;
    short int temp[8];

    puts("\tVariable sizes\n");
    printf("char variable c = %d\n" , sizeof(c));
    printf("int variable i = %d\n" , sizeof(i));
    printf("long variable x = %d\n" , sizeof(x));
    printf("float variable f = %d\n" , sizeof(f));
    printf("double variable d = %d\n", sizeof(d));
    putchar('\n');

    puts("\n\n");
    printf("Size of the temp array = %d\n", sizeof(temp));

    x=0;
    for(x=0; x<35; x++)
        putchar ('*');
    puts("\n\n");

    printf("Memory location of char variable c = %p\n",&c);

    printf("Memory location of int variable i = %p\n",&i);
    printf("Memory location of long variable x = %p\n",&x);
    printf("Memory location of float variable f = %p\n",&f);
    printf("Memory location of double variable d = %p\n",&d);
    for(i=0; i<8; i++)
        printf("Memory location of temp[%d] = %p\n\r" , i, &temp[i]);
/*! & e obligatoriu atunci cand vrei locatia pentru un element din array
Nu e obligatoriu atunci cand vrei locatia pentru tot array-ul !
/*! locatia pentru temp[] sare din 2 in 2 pt ca temp e un array de tipul short int
care ocupa 2 spatii in memorie ;-) */

/*!The printf() placeholder %p is used to display the address value in
hex. %p is the pointer placeholder. The only type of variable that can
properly hold a memory location is a pointer.*/

    getchar();


//! Variabilele respective le-am declarat,
//! dar nu le-am initializat !

//! Un byte = 8 bits !!!

    exit (32467);
}

