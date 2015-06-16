#include <stdio.h>

char * binString(int);

int main(void)
{
	unsigned short int value;

	printf("Please a number 0-65.535 %c ", 16);
	scanf("%d", &value);

	printf("%d is 0x%X in decimal and ", value, value);
	printf("%s in binary.", binString(value));

	while(getchar() != '\n')
		continue;
	getchar();
	return 0;
}

char * binString(int value)
{
	static char binary[100];
	static char rev_bin[100];  	//v. B U G

	//char *b = binary;  //pot sa trimit direct array-ul
	//(care ~e tot un pointer)

	int x, y;

	for (x = 0; value > 0; x++)
	{
		binary[x] = (value % 2) ? '1' : '0';
		value >>= 1;
	}

	binary[x] = '\0';

/*****************B U G**********************
* Nush dc dar binary-ul e salvat invers
* Ex: 8 e salvat ca 0001 in loc de 1000
*********************************************
**************Temp fix***********************
Nu e defapt bug...
Algoritmul folosit de mine e de asa natura...
Tre sa gasesc unul mai bun..
*********************************************/

/*Aflu cate caractere are array-ul*/
	x=0;
	while(binary[x] != '\0')
		x++;

/*Scriu in oglinda caracterele - temp fix*/
	for(y=0; x>=0; x--, y++)
		rev_bin[y] = binary[x-1];  //la x e null char

/*null char la sf stringului*/
	rev_bin[y] = '\0';

/*returnam string-ul inversat*/
	return rev_bin;
}