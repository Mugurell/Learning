/*
** Write a function called my_strrchr with this prototype: 
** char *my_strrchr( char const *str, int ch );
** The function is similar to strchr except that it returns a pointer
** to the last (rightmost) occurrence of the character. 
*/

#include <stdio.h>
#include <unistd.h>

char *my_strrchr( char const *str, int ch );

int main(void)
{
	char string[100] = {""};
	char litera;
	char *buffer;
	int x = 0;

	puts("\nSay something nice:");
	fgets(string, 100, stdin);
	printf("Now what char should I search for? : ");
	litera = getchar();
	puts("ok, let's get to it!");


	while(string[x] != '\0') {
		sleep(1);
		printf("\t%p is %c\n", &string[x], string[x]);
		x++;
	}

	buffer = my_strrchr(string, litera );
	if(buffer == NULL)
		printf("Nope, your string is free from %c's\n\n", litera);
	else {
		puts("After extensive search in your string..");

		printf("\tI've found the last of %c's:\n", litera);
		printf("\t%p says %c\n\n", buffer, *buffer);
	}

	return 0;
}

char *my_strrchr( char const *str, int ch )
{
	char *location = NULL;

	while(*str != '\0') {
		if(*str == ch)
			location = str;
		str++;
	}
	return location;
}