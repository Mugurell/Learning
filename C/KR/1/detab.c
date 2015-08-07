/*****************************************************************************
* Write a program detab that replaces tabs in the input with the proper number
* of blanks to space to the next tab stop.
* Assume a fixed set of tab stops, say every n columns.

* Should n be a variable or a symbolic parameter?
*****************************************************************************/

/*
** Ce am inteles eu:
** Un program care imi citeste stdin si imi inlocuieste tab cu
** numarul corespunzator de spatii. Ex: 1 tab = 5 spatii.
*/

#include <stdio.h>

int main(void)
{
	char c;

	while ((c = getchar()) != '~')
	{	//Daca citesti tab, il inlocuiesti cu 4 spatii (aparent tab pune 5 spatii -> to make it obvious)
		if (c == '\t')
			printf("1234");
		else
			printf("%c", c);
	}
	while (getchar() != '\n')
		continue;

	getchar();

	return 0;
}

