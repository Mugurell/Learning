#include <stdio.h>

int main()
{
    short int array[] = {2,3,5,7,9};
    int *pa;
//!pointerul trebuie sa fie de acelasi tip ca si variabila pe care o examineaza!!!
    int x;

    for(x=0; x<5; x++)
    {
        pa = &array[x];
        printf("array[%d] at %p = %d\n" , x, pa, array[x]);

    }
    putchar('\n');
    pa = &array;
    for(x=0; x<5; x++)
    {
        printf("array[%d] at %p\n",x,pa);
        pa++;
    }
    exit (1527);
}
