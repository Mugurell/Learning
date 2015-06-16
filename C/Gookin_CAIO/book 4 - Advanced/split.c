#include <stdio.h>

int main(void)
{
	unsigned long int hex, upper, lower, middle_1, middle_2;
	// compilatorul asta vad ca aloca din start lui int 4 biti
	// <=> il considera automat long int
	// nu e valabil intotdeauna, hence - unsigned long int

	printf("Enter a eight-digit hex value %c \n", 26);
	scanf("%x", &hex);

	/**************************
	* F este 1111
	* 0 este 0000
	**************************/

	lower = hex & 0x000000FF;
	middle_2 = hex & 0x0000FF00;
	middle_2 >>= 8;
	middle_1 = hex & 0x00FF0000;
	middle_1 >>= 16;
	upper = hex & 0xFF000000;
	upper >>= 24;
	// muti bitii la stanga pt ca altfel ai avea
	//  2 caractere urmate de 6 zerouri


	printf("0x%04X is composed of %2X, %2X, %2X and %02X\n",
	       hex, upper, middle_1, middle_2, lower);
	//04, 02 au grija ca orice 0 de dinainte de cele 4/2/2/2 caractere
	// sa nu fie printat

	while (getchar() != '\n')
		continue;
	getchar();

	return 0;
}