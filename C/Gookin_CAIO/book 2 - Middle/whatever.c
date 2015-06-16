#include <stdio.h>
#include <math.h>
#define NUMAR 5
#define PUTEREA 413

int main()
{
	double rezultat;
	rezultat = pow(NUMAR , PUTEREA);
	printf("   %d la puterea %d = %.9E", NUMAR, PUTEREA, rezultat);
	printf("\n\n   Adica %.f\n", rezultat);
	 return (0);
}