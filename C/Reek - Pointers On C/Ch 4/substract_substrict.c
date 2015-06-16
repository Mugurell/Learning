/*  Write a function that extracts a substring from a string.
The function should have the following prototype: 
 
int substr( char dst[], char src[], int start, int len )
 
It should copy the string that begins start characters 
past the beginning of the string in src into the array dst.
At most len non‐NUL characters should be copied from src. 
After copying, dst must be NUL‐terminated. 
The function should return the length of the string stored in dst. 
If start specifies a position beyond the end of the string in src,
or either start or len are negative, then 
dsc should be given the empty string. */


#include <stdio.h>

#define MAX_CHAR 100

int substr(char dst[], char src[], int start, int len);

int main(void)
{
	char dest[MAX_CHAR];
	char string[MAX_CHAR];
	int start;
	int len;

	puts("Say something cool from which to copy:");
	fgets(string, MAX_CHAR, stdin);
	printf("Ok, now from which ch forward do you want me to copy?: ");
	scanf("%d", &start);
	printf("\nAnd at which ch would you like me to stop?: ");
	scanf("%d", &len);
	puts("\n\nCool!");
	printf("So you should have %d characters left..", substr(dest, string, start, len));
	puts("\n\tWhich should be..");
	puts(dest);
	puts("\n");

	return 0;
}

int substr(char dst[], char src[], int start, int len)
{
	int x, y;
	/* For the first character to be 1 and not 0 */
	start -=1; 		

	for(x=start,y=0; x<len; x++, y++)
		dst[y] = src[x];
	dst[y] = '\0';

	return(len-start); 
}


