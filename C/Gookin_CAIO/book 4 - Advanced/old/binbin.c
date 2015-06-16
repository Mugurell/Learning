#include <stdio.h>

void main_1(void);
void main_2(void);

void binString (int n);
char *binstring (int n);


int main()
{
    main_1();

    puts("\n\n");
    return 0;
}

void main_1(void)
{
    unsigned short int value;
    int x;

    printf("Enter an integer value, 0 to 65,535 %c ", 16);
    scanf("%d" , &value);

    printf("\nDecimal    Hexadecimal   Binary\n");


    for(x=0; x<40; x++)
    putchar('*');

    printf("\n%7d\t", value);
    printf("   0x%09X\t", value);


    binString(value);

    putchar('n');
}

void binString (int n)
{
    char bin[17];
    int x;

    for(x=0; x<16; x++)
    {
        bin[x] = n & 0x8000 ? '1' : '0';
        n <<=1;
 //       printf("bin[x] = %d\n", bin[x]);
//        printf("%d\n" , n);
//!bin [x] e '1' sau '0' in functie daca primul numar din n (cel mai din stanga e 1 sau 0
/*  if(n & 0x800)
*       bin[x] = '1';
*   else
*       bine[x] = '0';
*/

    }
    bin[17] = '\0';     //!al 16-lea bit e NULL
    printf("%s" , bin);
}


/*! ce e mai jos e unfinished...
void main_2(void)
{
    unsigned short int value;

    printf("Enter an integer value, 0 to 65.535: ");
    scanf("%d" , &value);

    printf("Decimal value is %d\n" , value);
    printf("Hexadecimal value is 0x%X\n", value);
    printf("Binary value is %s\n",binString(value));
}

char *binstring(int n)
{
    static char bin [17];       //! must be static - zice gookin
                                //! dupa ce se termina o functie, n-o mai intereseaza valorile
                                //! variabilelor din ea, care se pierd ...


	int x;

	for(x=0;x<16;x++)
	{
		bin[x] = n & 0x8000 ? '1' : '0';
		n <<= 1;
	}
	bin[16] = '\0';
	return(bin);
*/

/*
   for(x=0; x<17; x++)
    {
       bin[16-x] = n%2;
       n /= 2;
       printf("%d\n", bin[x]);
    }

    return(bin);

}
*/
