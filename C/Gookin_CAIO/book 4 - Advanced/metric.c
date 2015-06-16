#include <stdio.h>

#define KMP 1.609344

int main(void)
{
	float miles, kilometers;
	float *pmiles, *k_address;


	printf("Enter a value in miles %c ", 16);
	scanf("%f", &miles);

	kilometers = miles*KMP;

	printf("\n%.2f miles works out to %.2f kilometers\n", miles, kilometers);

	pmiles = &miles;
	printf("\nVariable 'miles' is %d bytes long at %p adress\n", sizeof(miles), pmiles);

	k_address = &kilometers;
	printf("Variable 'kilometers' is %d bytes long and lives at %p", sizeof(kilometers), k_address);

	while(getchar() != '\n')
		continue;
	getchar();

	return 0;

}
