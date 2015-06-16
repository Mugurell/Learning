#include <stdio.h>

int increment(int);
int negate(int);

int
main(void)
{
	puts("\n10 incremented inversed");
	printf("\t%d\t%d\n", increment(10), negate(10));

	puts("\n0 incremented inversed");
	printf("\t%d\t%d\n", increment(0), negate(0));

	puts("\n-10 incremented inversed");
	printf("\t%d\t%d\n", increment(-10), negate(-10));

	return 0;
}