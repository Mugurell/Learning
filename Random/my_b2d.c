#include <stdio.h>


int main()
{
    char bin[20] = "0";
    int x;
    int dec_total = 0;
    long unsigned int dec = 1;

    printf("\tThe Amazing Binary to Decimal Conveter\n\n\a");

    printf("Enter here the bin23 number you want to be converted to decimal %c ", 16);
    scanf("%s" , bin);
    while(getchar() != '\n')
        continue;

    for(x=0; x<20; x++)
    {
        if(bin[x] == '1')
        {
            dec_total += dec;
            dec <<= 1;
        }

        else
            dec <<= 1;
    }

    printf("\n\n%s\n\tin\n\tdecimal\n\tis\n\t\t%d" , bin, dec_total);
    puts("\n\n\n");

    getchar();


    return 0;

}
