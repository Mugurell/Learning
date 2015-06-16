#include <stdio.h>

int main()
{
    float rootbeer;
    float *pr;

    pr = &rootbeer;
    printf("The adress of the float variable 'rootbeer' is %p" , pr);
    printf("\nThe next float in memory will be at ??? %c", 25);
    puts("\n\n\n\n");
    printf("\t\t\t\t\t\t%p", pr+1);
    printf("\t\t\t\t\t\t\t\t\t********");


    printf("\n\n*Tip: according to the sizeof operator, rootbeer is %d bytes.", sizeof(rootbeer));
    printf("\n*The point to remember is that pointer math isn’t incremental, like regular math \; \
    rather, the pointer is manipulated in chunks. The size of the chunks\
    are equal to the variable size.");

    getchar();

    return 768;
}
