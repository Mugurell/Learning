#include <stdio.h>

int main()
{
    char bin[20];
    int x, dec, dec2;

    printf("\tThe Amazing Decimal to Binary Conveter\n\n\a");
    printf("Enter the number of which you want to know it's binary value %c ", 16);
    scanf("%d" , &dec);
    dec2 = dec;
    printf("\n%d\n\n", dec2);
    puts("\tin");
    puts("\tbinary");
    puts("\tis\n");

//    printf()
    while(getchar() != '\n')
        continue;

    for(x=20; x>=0; x--)
    {

        bin[x] = (dec%2) ? '1' : '0';
        dec /= 2;
    }

    for(x=0; x<=20; x++)
    {
        if (bin[x] == '0')
           bin[x] = '\r';
        if (bin[x] == '1')
            break;
    }

 //   printf("\n%d in binary is %s" , dec2, bin);
 //! se intampla ceva foarte ciudat daca pastrez printf-ul asta....
    printf("%s" , bin);
    puts("\n\n\n");
    getchar();

    return 0;
}


