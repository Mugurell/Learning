#include <stdio.h>

int main(void)
{
	int vector[] = {23,54,54,65,6,7};
	printf("\nSizeof vector = %lu and sizeof vector[0] = %lu\n",
		sizeof vector, sizeof vector[0]);

	char array[] = {"Hello"};
	printf("Sizeof array = %lu and sizeof array[0] = %lu\n\n",
		sizeof array, sizeof array[0]);

	return 0;
}