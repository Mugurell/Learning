#include <stdio.h>
#include <math.h>
#define NUMAR 5
#define PUTEREA 0.5

int main()
{
	float radical = sqrt(NUMAR);
	float putere = pow(NUMAR , (float)PUTEREA);
	
	puts("  √5 == 5  la 1/2\n");
	puts("  Demonstratie:");
	printf(" Radical din %d = %f\n" , NUMAR , radical );
	printf(" La fel cum %d la puterea %.1f = %f\n" , NUMAR , PUTEREA , putere);
	
	
	
	return(0);
	
	}