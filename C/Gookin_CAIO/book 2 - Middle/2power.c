#include <stdio.h>
#include <math.h>

int main()
{
	double two;
	int exponent;

	puts("Power of 2's table:\n");

	for (exponent = 0; exponent <= 10; exponent++)
	{
		two = pow(2.0, (float) exponent);          //poate sa fie si float si double
		printf("2 to the %2d power is %.f\n", exponent, two);
	}

	return (0);
}