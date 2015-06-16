#include <stdio.h>
#include <string.h>
#include <stdlib.h> 	//necesar pt malloc

int main(void)
{
	char *string;

	string = (char *)malloc(80);

/* malloc returneaza fie inceputul blocului de memorie pentru care a alocat spatiu
* fie returneaza NULL (NULL pointer sau valoarea 0) daca nu reuseste sa aloce spatiu/.
* NULL e definit in stdio.h
*/
	if(string == NULL)
	{
		puts("Not enough memory!");
		return 0;
	}

	strcpy(string, "Howdy! Howdy! Hi!");
	printf("%s", string);

	getchar();
	return 0;
}