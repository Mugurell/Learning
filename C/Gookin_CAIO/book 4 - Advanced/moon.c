#include <stdio.h>

int main(void)
{
	float duration, *d;
	float distance = 378921.46;
	float speed = 140;

	d = &distance;
	printf("The moon is %.2f km away.\n", *d);

	d = &speed;
	printf("Travelling at %.f kph,\n", *d);

	d = &duration;
	*d = distance/speed;
	printf("it would take %.2f hours to the drive to the moon\n", *d);

	getchar();

	return 0;
}