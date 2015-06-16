#include <stdio.h>


int *greatest(int a, int b, int c);

int main()
{
    int *p;

    p = greatest (5, 25, 16);
//! nu e adresa pointerului (aia e &p)
//! p e adresa functiei !!!
//! pointerul e o variabila ce contine o adresa!!!

    printf("The greatest value is %c %d\n", 16, *p);

    return 0;
}

int *greatest (int a, int b, int c)
{
    int *g;

    if(a>b && a>c) g = &a;
    else if(b>a && b>c) g = &b;
    else g = &c;

    return(g);   //!g in cazul asta fiind adresa pointerului g
}
