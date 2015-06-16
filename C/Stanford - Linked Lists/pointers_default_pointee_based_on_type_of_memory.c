/*
** Ok, pointerul stocat in ordinary mem e auto initializat la NULL.
** Dar lucruri interesante/ciudate se intampla cu pointerii 
** stocati in stack..
** Hint: Joaca-te cu numarul lor si priveste adresele ;-)
*/


#include <stdio.h>

int *pointer;

int main(void)
{
	int *ptr;
	char *prt;
	char *pter;

	printf("\nPointerul din ordinary mem e %p\n", pointer);
	printf("\nPointerul din stack e %p\n", ptr);
	printf("\nSi al 2-lea pointer din stack e %p\n", prt);
	printf("\nSi al 3-lea pointer din stack e %p\n", pter);
	return 0;
}