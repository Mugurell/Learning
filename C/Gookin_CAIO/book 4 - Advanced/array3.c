#include <stdio.h>

void showArray(int *, int);
void modArray(int *, int);

int main(void)
{
	int primes[] = {1,3,5,7,11,13};
	//int *p = primes;	
	int size = sizeof(primes)/4;		//4 is the size of a long int

	puts("Original Array:");
	showArray(primes, size);		//un array e un pointer mai special
	modArray(primes, size);
	puts("\n\nModified Array:");
	showArray(primes, size);

	getchar();
	return 0;
}

void showArray(int *array, int size)
{
	int x = size;
	while(x--)
		printf("Element %d: %d\n", x, *(array+x));
}

void modArray(int *array, int size)
{
	int x = size;
	while(x--)
		*(array+x) *= 2;
}