#include <stdio.h>

void binString(int value);

int main(void)
{
	unsigned short int value;

	printf("Enter an integer value, 0 to 65535 %c ", 16);
	scanf("%d", &value);

	printf("\n\nThe binary value is \t");
	binString(value);
	putchar('\n');

	value = ~value;

	printf("One's complement is\t");
	binString(value);
	putchar('\n');

	while(getchar() != '\n')
		continue;
	getchar();

	return 0;
}

void binString(int value)
{
	char bin[17];
	int x;

	for(x=15; x>=0; x--)
	{
		bin[x] = value%2 ? '1' : '0';
		value >>= 1;
	}
	bin[16] = '\0';

	puts(bin);
}