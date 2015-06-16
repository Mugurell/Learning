/************************************************************************************
* Exercise 2-3. Write the function htoi ( s), which converts a string of hexadecimal
* digits (including an optional Ox or ox) into its equivalent integer value.
* The allowable digits are O through 9, a through f, and A through F.
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>			//necesar pt atoi

int
main(void)
{
	int x, y;
	int limit;			// the fix lenght of a hex number = 8 
	char c;
	char hex[10] = {'1' , '3'};
	char string[1000];

	printf("Simon says %d\n", 0x847fac);
	printf("0x%X is 0x847fac\n", 8683436);
	printf("atoi de hex e %d", atoi(hex));


	x=0;
	while((c=getchar()) != '~')
		string[x++] = c;
	string[x] = '\0';

	for(y=0; y<x; y++)
	{
		if((string[y] == '0') && (string[y+1] == 'x' || string[y+1] == 'X'))
			{
			//	state = IN;
				x=2;
				hex[0] = string[y];
				hex[1] = string[y+1];
			//	limit = y+8;			//un numar hex are 8 caractere(inc 0x) (+ 1 - null char cand il stochezi in string)
				for(limit=y+2; limit<y+8; limit++)
					if((string[limit] >='0' && string[limit] <='9') || (string[limit] >='a' && string[limit] <='z') || (string[limit] >='A' && string[limit] <='Z'))
						hex[x++] = string[limit];
					hex[x] = '\0';
			}
	}

	printf("Numarul tau hex, %s", hex);
//	for(x=0; x<8; x++)
//		printf("%c", hex[x]);

	printf(" este egal cu %d", atoi(hex));
	printf("\n Iar 2686714 este egal cu 0x%X", 2686714);


	fflush(stdin);
	getchar();

	return 0;
}