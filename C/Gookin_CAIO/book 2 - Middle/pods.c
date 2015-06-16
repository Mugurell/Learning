#include <stdio.h>
#define PODS 50
#define LOCATIONS 0xBA3C

int main()
{
	float var = 6.27E-4;
	
	puts("Base 10");
	printf("I must deliver %d pods to %d locations\r\n\n" , PODS , LOCATIONS);
	puts("Base 16");
	printf("I must deliver 0x%x pods to 0x%X locations\n\n" , PODS , LOCATIONS);
	puts("Base 8");
	printf("I must deliver %o pods to %o locations\n\n" , PODS , LOCATIONS);
	puts("Scientific representation");        /* %E sau %G */
	printf("I must deliver %E pods to %E locations\n" , (float)PODS , (float)LOCATIONS);
	printf("I must deliver %G pods to %g locations\n\n" , (float)PODS , (float)LOCATIONS);
	
	printf("\t\*Test for scientific to integer (e=g=f=d)\n\t  float var = 6.27E-4 = \t%e = %g , %f , %d" , var , var , var , var);
	
	return(0);
	}