/*
** Take an integer value (unsigned), convert it to characters and print it.
** Leading zeros are suppresed.
*/

#include <stdio.h>

void binary_to_ascii(unsigned int number_to_be_converted);

int main(void)
{
	unsigned int number;

	printf("\nEnter here a number to be converted to characters: ");
	scanf("%u", &number);

	puts("\n\tCool!");
	puts("\nSo that number, when viewed as characters would be");
	printf("\n\t...\n\t   ");

	binary_to_ascii(number);

	puts("\n");
	return 0;
}

void binary_to_ascii(unsigned int number)
{
	unsigned int 	quotient;	/* rest */

	/* Impartim la 10 numarul decimal pt a obtine
	** cea mai din dreapta valoare */
	quotient = number / 10;

	/* Daca intregul e mai mare de 0 (mai sunt alte numere)
	** chemam iar functia asta - RECURSIVE FUNCTION */
	if(quotient != 0)
		binary_to_ascii(quotient);

	/* Dupa ce am chemat si ultima data functia,
	** pentru cel mai mare decimal,
	** ne apucam sa printam caracterul corespunzator.
	** Toate caracterele - pentru toate decimalele -
	** sunt printate abia acum, unul dupa altul,
	** pornind de la cel mai mic pana la cel mai mare decimal
	** (ca si pozitie in numar) b*/
	putchar(number % 10 + '0');
}

