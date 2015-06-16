#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char name[64];
	char command[64];

	printf("Please enter your name: ");
	gets(name);
	strcpy(command,"beta \"");		//incepe prin a copia in command: beta "
	strcat(command,name);			// apoi pune si name -> beta "name
	strcat(command,"\"");			// inchide ghilimelele -> beta "name"
	system(command);				//trimite catre sistem: beta "name"

	return(0);
}

