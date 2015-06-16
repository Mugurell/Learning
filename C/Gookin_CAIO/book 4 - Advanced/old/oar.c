#include <stdio.h>

void binString(int n);

int main()
{
 /*   int twos[] = { 1, 2, 4, 8,
*                16, 32, 64, 128,
*               256, 512, 1024, 2048,
*              4096, 8192, 16384, 32768
*           };
*/

    int twos = 1;
    int x, r;
    unsigned short int v = 0;

    for(x=0; x<16; x++)
        {
            r = v | twos;
            printf("0x%04X | %6d = 0x%04X or ", v, twos, r);
            binString(r);
            putchar('\n');
            twos <<= 1;
        }

    exit (56234);
}

void binString (int n)
{
    char bin[17];
    int x;

    for (x=0; x<16; x++)
    {
        bin[x] = n & 0x8000 ? '1' : '0';
        n<<=1;

//! n e defapt r
    }
    bin[16] = '\0';  //! - NULL character
    printf("%s" , bin);
}
