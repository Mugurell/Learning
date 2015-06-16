#include <stdio.h>

int main(void)
{
	int nr[10];

	printf("\nValoarea lui nr[1] este %d", nr[1]);
	printf("\nIar adresa lui nr[1] este %p.\n", &nr[1]);

	printf("\nValoarea lui nr[2] este %d", nr[2]);
	printf("\nIar adresa lui nr[2] este %p.\n", &nr[2]);

	printf("\nValoarea lui nr[3] este %d", nr[3]);
	printf("\nIar adresa lui nr[3] este %x.\n", nr[3]);

	return 0;
}