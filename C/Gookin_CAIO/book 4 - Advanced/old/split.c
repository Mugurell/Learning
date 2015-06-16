#include <stdio.h>

int main()
{
    unsigned long int hex, h1, h2, l1, l2;
/*    long unsigned int y;

    printf("Sizeof(y) = %d\n\n", sizeof(hex));
*/
    printf("Enter a eight-digit hex value: ");
    scanf("%x" , &hex);

    h1 = hex & 0xFF000000;
    h2 = hex & 0x00FF0000;

    l1 = hex & 0x0000FF00;
    l2 = hex & 0x000000FF;

    h1 >>= 24;
    h2 >>= 16;
    l1 >>= 8;
//    printf("** la adresa %x sta %d **\n\n", 0xA12B, 0xA12B);

    printf("0x%08X is composed first of %02X and %02X, then %02X and %02X\n", hex, h1, h2, l1, l2);
//! 04, 02 si 02 sunt spun defapt cate caractere sa aiba respectivul numar

    exit (65789);
}
