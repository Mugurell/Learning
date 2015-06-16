#include <stdio.h>

void showArray(int array[]);

int main(void)
{
	int primes[] = {2,3,5,7,11,13};

	showArray(&primes[2]);
	//When you’re dealing with arrays and pointer  
	//  the array name by itself is used to represent  
	//  the starting address for the array. 
	//Only when you reference individual elements in the
	//  array do you bother with the '&'.

	getchar();
	return 0;
}

void showArray(int array[])
{
	int x;

	for(x=0; x<6; x++)
		printf("Element %d: %d\n", x, array[x]);
}