#include <stdio.h>

void showArray(int *, int);

int main(void)
{
	int primes[] = {25,3,5,7,11,13};
	int *p = primes;
	int size = sizeof(primes)/4;   //4 is the size of a long int

	showArray(p, size);

	getchar();
	return 0;
}

void showArray(int *array, int size)
{
	int x;

	printf("Size = %d\n", size);

	for(x=0; x<size; x++)
		printf("Element %d: %d\n", x, *(array+x));
}