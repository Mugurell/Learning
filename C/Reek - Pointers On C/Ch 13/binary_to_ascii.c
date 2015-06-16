#include <stdio.h>

void b2a(unsigned int);

int main(void)
{
	int n;

	printf("Enter a number to be converted to ASCII: ");
	scanf("%d", &n);

	b2a(n);

	return 0;
}

void b2a(unsigned int value)
{
	unsigned int quotient;
	quotient = value/10;

	if (quotient != 0)
		b2a(quotient);

	putchar(value % 10 + '0');
	puts("\n");
}