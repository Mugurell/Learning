#include <stdio.h>

int strlenght(char *);

int main(void)
{
	printf("Nr de caractere = %d", strlenght("This is a string."));

	getchar();
	return 0;
}

int strlenght(char *string)
{
	int x=0; 

	puts(string);
	while(*string++)
		x++;
	return x;
}