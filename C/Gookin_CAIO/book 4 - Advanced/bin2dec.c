#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bin2dec(char *);

int main(void)
{
	char input[100];
	char *i = input;        //necesar un pointer de tip char pt fgets
	printf("Please enter a binary number %c ", 16);
	fgets(i, 100, stdin);

	printf("\n\nThat is in fact ");
	bin2dec(i);
	puts(" in decimal.");

	getchar();

	return 0;
}

void bin2dec(char *i)
{
	int x, limit, dec = 0;
	int count = 1;		//va stoca 2 - la puterea n(array-ul binar)


	limit = strlen(i);      //cate cifre sunt in string, inclusiv null si linia noua

//ideea e sa ai un counter care numara si auto incrementeaza <<=1 
// pt fiecare x++
// daca in bin e 1 se aduna la dec, daca nu (bin[x] = 0) - numeri in cont samd

	for (x = limit - 2; x >= 0; x--)		//limit-2 : sarim \0 si \n
	{
		if (i[x] == '1')
		{

//			printf("**i[x] = %c**\n", i[x]);
			dec += count;			
			count <<= 1;
//			printf("***count = %d***\n", count);
//			printf("*** dec = %d***\n", dec);
		}
		else
		{	
//			printf("**i[x] = %c**\n", i[x]);
			dec += 0;		//necesar in cazul in care valoarea introdusa este doar un 0
			count <<=1;
		}
	}

	printf("%d", dec);

}