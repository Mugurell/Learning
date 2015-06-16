#include <stdio.h>
#include <stdlib.h> 	//necesar pt malloc
#include <string.h>

int main(void)
{

	char input[100];
	char *string;
	int len = 0;
	int x = 0;

	printf("Say something %c\n", 25);
	fgets(input, 100, stdin);		//fgets imi numara si '\n'
	// gets(input);					//gets se opreste inainte de '\n'

	while (input[x] != '\0')
	{
		len++;
		x++;
	}
	len -= 1; 		//scadem linia noua citita de fgets

	string = (char *)malloc(len*sizeof(char));

	string = input;		
	//TREBUIE initializat pointerul DOAR DUPA ce i-am alocat memorie

	/* malloc returneaza fie inceputul blocului de memorie pentru care a alocat spatiu
	* fie returneaza NULL (NULL pointer sau valoarea 0) daca nu reuseste sa aloce spatiu/.
	* NULL e definit in stdio.h
	*/
	if (string == NULL)
	{
		puts("Not enough memory!");
		return 0;
	}

	printf("\n\tOriginal String\n%s\n\n\tPointer string\n%s", input, string);

	getchar();
	return 0;
}