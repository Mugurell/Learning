#include <stdio.h>
#include <stdlib.h>

int main()
{
    double *pointer;
    int x;
    unsigned long int space = 0;


    pointer = (double*)malloc(2);

    for(x=99999999; x<9999999999999999; x++)
    {
        space =+x;
        if(pointer == (char *)NULL)
        {
            printf("Out of memory");
            return 0;
        }
        else
        {
            pointer =(double *) malloc(x);
        }
        x += x;

        printf("Pointer occupies %d\n", space);

    }

    return 0;
}
