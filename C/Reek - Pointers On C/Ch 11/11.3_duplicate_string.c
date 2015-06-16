#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strdup(char const *string);

int main(void)
{
	char string[101];		/* 100 chars + nul */
	char *buffer;
	puts("\nEnter a string to be copied: ");
	fgets(string, 101, stdin);
	puts("\nCool!");

	buffer = strdup(string);
	printf(".\nBut after copying it now says.. %s", buffer);
	printf("and is has %lu bytes \n\n", sizeof(buffer));


	return 0;
}

char *strdup(char const *string)
{
	char *pstr;

	puts("So atm the location says:");
	/* O adresa de memorie privita ca string
	** ... printeaza .. un string! */
	puts(pstr);
	printf("And it has %lu bytes\n", sizeof(pstr));

	pstr = malloc(strlen(string) + 1);
	if(pstr != NULL)
		strcpy(pstr, string);

	printf("Now it has %lu bytes\n", sizeof(pstr));

	return pstr;
}