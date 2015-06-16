#include <stdio.h>\
//#include <stdlib.h>

int main()
{
    char array [] = "Hello";
    int a_len = strlen(array);
 //   printf("****strlen = %d****" , a_len);
    int x=0;
    char *a, *e;

    printf("\t%s\n" , array);
    puts("\n\n");

    printf("Array 'array' is %d bytes long and is located\n\tat the adress %p." ,\
           sizeof(array),\
           a);
    puts("\n");
    for(x=0; x<=a_len; x++)
    {
        e = &array[x];

        switch (x)
        {
        case 0:
            printf("First element of 'array' is %d byte long and is located at %p adress.\n",\
                   sizeof(array[x]),\
                   e);
                   break;
        case 1:
            printf("The %dnd element of 'array' is %d byte long and is located at %p adress.\n",\
                   x+1,\
                   sizeof(array[x]),\
                   e);
                   break;
        default:
            printf("The %dth element of 'array' is %d byte long and is located at %p adress.\n",\
                   x+1,\
                   sizeof(array[x+1]),\
                   e);
                   break;
        }
    }

    x=0;
    putchar('\n');
    for(x=0; x<a_len; x++)
        printf("Adress %p says \"%c\"\n", &array[x], array[x]);

    getchar();

    exit(975342);
}
