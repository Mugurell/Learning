/*****************************************************************
* Exercise 1-18.
* Write a program to remove trailing blanks and tabs
* from each line of input, and to delete entirely blank lines.
*****************************************************************/

#include <stdio.h>

int
main()
{
	char c, prop[1000];
	int x = 0;


	do
	{
		c = getchar();
		if ((c == ' ') || (c == '\t') || (c == '\n'))
			continue;
		else
			prop[x++] = c;
	} while (c != '~');

	prop[x - 1] = '\0';     //-1 pentru ca prop[x++] a incrementat x-ul dupa ce l-a folosit

	putchar('\n');
	puts(prop);

	fflush(stdin);

	getchar();


	return 0;
}