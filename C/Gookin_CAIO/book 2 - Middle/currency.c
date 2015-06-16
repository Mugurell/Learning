#include <stdio.h>

#define POUNDS 0x9c
#define YEN 0x9e

int main()
{

	float amount, bp, jy;
	float d2p = 0.5407;			/* dollars per pound */
	float d2y = 106.79;			/* dollars per yen */

	printf("Enter the amount in dollars : $ ");
	scanf("%f", &amount);
	bp = amount * d2p;
	jy = amount * d2y;
	puts("\nCurrency converter ...");
	printf("\t%c%9.2f\n", POUNDS, bp);
	printf("\t%c%9.f\n", YEN, jy);

	return (0);
}