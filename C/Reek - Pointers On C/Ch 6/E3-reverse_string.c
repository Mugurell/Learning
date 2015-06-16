#include <stdio.h>

void reverse_string( char *str );

int main(void)
{
	char string[100];

	puts("Say something nice:");
	fgets(string, 100, stdin);

	puts("Reverse of that would be..");
	reverse_string(string);
	puts(string);

	return 0;
}

void reverse_string( char *str )
{
	char *last_char;

	/*
	** Set last_char to point to the last character
	** in the string.
	*/
	for(last_char = str; *last_char != '\0'; last_char++)
		;
	last_char--;

	/*
	** Interchange the characters that str and last_char point to,
	** advance str and move last_char back one,
	** and keep doing this until the two pointers meet or cross
	*/
	while(str < last_char) {
		char temp;

		temp = *str;
		*str++ = *last_char;
		*last_char-- = temp;
	}
}
