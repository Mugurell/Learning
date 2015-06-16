#include <stdio.h>

void mystery(int);

int main(void)
{
	int number;
	printf("\nEnter a number and... something .. will happen.. : ");
	scanf("%d", &number);

	mystery(number);

	return 0;
}

void mystery(int n)
{
	n += 5;
	n /= 10;
	printf("%s\n", "**********" + 10 - n);
}