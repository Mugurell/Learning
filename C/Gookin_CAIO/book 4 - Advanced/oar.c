#include <stdio.h>

int main(void)
{
	int twos[] = {1,	2,		4,		8,
				  16,	32,		64,		128,
				  256,	512,	1024,	2048,
				  4096, 8192,	16384,	32768};
	int x, r, tus = 1;
	unsigned short int v = 0;

	for(x=0; x<16; x++)
	{
	//	r = v | twos[x];
	//	printf("0x%04X | %5d = 0x%04X\n", v, twos[x], r);
		r = v | tus;
		printf("0x%04X | %5d = 0x%04X\n", v, tus, r);
		tus <<= 1;   	// in felul asta nu am nevoie de matrice
	}

	getchar();

	return 0;
}