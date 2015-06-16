/*
** Write the function for the following prototype: 
** int ascii_to_integer( char *string );
**
** The string argument must contain one or more digits, and the function
** should convert those digits to an integer and return the result.
** If any nondigit characters are found, return the value zero instead.
** Do not worry about arithmetic overflow.
*/

#include <stdio.h>

int ascii_to_integer(char *string);

int
main(void)
{
	char string[10];
	int x = 0;

	printf("\nEnter 1-10 or more digits to be converted to integers:\n\t");
	fgets(string, 10, stdin);

/*
** Make sure there are no characters in the string
** and that the string does not exceed 10 digits
** CAREFULL
** fgets also include new line(ASCII 10) in the string
*/
	while(string[x] != '\n') {
		if(string[x] < 48 || string[x] > 57 ) {
			printf("**Character #%d is %c (not a digit)**\n", x+1, string[x]);
			puts("Naughty! :-P\n\n");
			return 0;
		}
		else 
			++x;
	}


	printf("\n\nCool! So that would be..\n");
	printf("\t%d\n\n", ascii_to_integer(string));

	return 0;
}

int
ascii_to_integer(char *string)
{
	int nr = 0;

//	while(*string != '\n') {
	while(*string >= '0' && *string <= '9') {
		nr *= 10;
		nr += *string - '0';
		string++;
	}
	return nr;	
}