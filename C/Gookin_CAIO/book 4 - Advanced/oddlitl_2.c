/***********************************************************
* Note:
* ----------------------------------------------------------
* sizeof operator is used to determine how many bytes 
* each variable sucks up.
*
* size of is a C language keyword! not a function !!
* Because sizeof is a keyword, it doesn’t require 
* a header file in order to work properly.
************************************************************/


#include <stdio.h>

int main(void)
{
	char c;
	short int i;
	short i2;
	long x;
	long int x2;
	float f;
	double d;
	char temp[8];
	double eight[8];

	puts("\tVariable sizes:\n");
	printf("Size of char variable c = %d\n", sizeof(c));
	printf("\tAnd its adress in memory is %p\n", &c);
	printf("Size of short int variable i = %d\n", sizeof(i));
	printf("Size of short variable i2 = %d\n", sizeof(i2));
	printf("Size of long variable x = %d\n", sizeof(x));
	printf("Size of long int variable x2 = %d\n", sizeof(x2));
	printf("Size of float variable f = %d\n", sizeof(f));
	printf("Size of double variable d = %d\n", sizeof(d));
	printf("Size of char temp[8] = %d\n", sizeof(temp));
	printf("  An it's location in memory is (hex to int):\n");
	for(i=0; i<8; i++)
		printf("\t%p -> %d\n", &temp[i], &temp[i]);
	printf("Size of double eight[8] = %d\n", sizeof(eight));

	getchar();

	return 0;
}