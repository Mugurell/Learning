#include <stdio.h>

int main()
{
	unsigned char c;

	for (c = 0; (unsigned)c < 128; c++)
	{
		printf("%c", c);
	}

	return (0);
}