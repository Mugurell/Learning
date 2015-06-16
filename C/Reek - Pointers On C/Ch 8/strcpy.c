#include <stdio.h>

void strcy(char *buffer, char const *string);
/* const specify that *string is read only */

int main(void)
{
	char	source	[100];
	char	dest	[100];

	printf("\nEnter a string to be copied into another:\n\t");
	fgets(source, 100, stdin);

	printf("\n\tCool!\nSo currently the dest string is:\n\t%s.\n", dest);
	strcy(dest, source);
	printf("But after copying ...\n\t%s\n", dest);
	puts("\tMagic huh?\n");

	return 0;
}

//void strcy(char buffer[], char const string[])
/************** Same thing ******************/
void strcy(char *buffer, char const *string)
{
	while((*buffer++ = *string++) != '\0')
		;
}