/* convert radians to degrees */

#include <stdio.h>

#define RAD 57.2957795

int main()
{
	float radians, degrees;

	puts("Convert radians to degrees\n\n");

	for (;;)
	{
		printf("Enter a value in radians : ");
		scanf("%f", &radians);

		degrees = radians * RAD;

		printf("%.5f radians equals %.3f degrees\n\n", radians, degrees);
		fpurge(stdin);
	}
	return (0);

}