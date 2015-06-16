#include <stdio.h>
#include <string.h>

int main()
{
    char input [64];
    int len, x;

    printf("Enter tonight's pass phrase: ");
    gets(input);
    len = strlen(input);

    for(x=0; x<len; x++)
        input[x] = 0x7F ^ input [x];
//! ^ da 1 atunci cand bitii sunt diferiti!

    puts("Press Enter to see the encrypted text:");
    getchar();
    printf("%s" , input);
 //   for(x=0; x<len; x++)
   //     putchar(input[x]);

    for(x=0; x<len; x++)
        input[x] = 0x7F ^ input[x];

    puts("Press Enter to see the text recovered");
    getchar();
    for(x=0; x<len; putchar(input[x++]))   //!liniile 18 si 19 combinate
        ;

    getchar();

    return 0;
}


