#include <stdio.h>
#define BIGGIE 2468000000000.0	/* 9 zeros before the . */
#define TEENSY 0.00000000097531	/* 9 zeros after the . */

int main()
{

	puts("Using %f :");
	printf("BIGGIE %f\t TEENSY %f\n", BIGGIE, TEENSY);
	puts("Using %E :");
	printf("BIGGIE %e\t TEENSY %E\n", BIGGIE, TEENSY);
	puts("Using %G :");
	printf("BIGGIE %G\t TEENSY %g\n", BIGGIE, TEENSY);

	return (0);

}