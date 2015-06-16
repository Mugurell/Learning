#include <stdio.h>
#define DEG 0.0174532925

int main()
{
	float radians, degrees;
	puts("\tRadians to degrees converter\n");

	for (;;)
	{
		printf("Please enter the value in degrees here : " );
		scanf("%f" , &degrees);
		radians = degrees * DEG;
		printf("\t%.2f degrees equals %f radians\n\n\n", degrees , radians);
	}
	return (0);
}