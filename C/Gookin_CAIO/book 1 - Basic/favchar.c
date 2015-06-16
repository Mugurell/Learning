#include <stdio.h>

int main()
{
	char fav;

	printf("Enter your favourite letter character :");

	fav = getchar();

	if (fav == 'q')        /*cand ai un singur statement pentru "if" acoladele sunt optionale*/
		printf("That's my favourite colur too!");
	 return (0);
}