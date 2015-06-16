#include <stdio.h>

void underline(char *);

int main(void)
{
	underline("This Year's Starting Line-Up");

	getchar();
	return 0;
}

void underline(char *array)
{
	puts(array);

	
	while (*array++)		//v. puke.c
// Whenever you see a while loop with *string
// (or something similar) as its condition,
// you can bet your bonnet that the loop is repeated
//until no more characters are in the string.
	{
		putchar('=');
		//	array++;
	}
	putchar('\n');
}