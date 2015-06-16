/* 
** Write this function: 
** int palindrome( char *string );
** which returns a true value if the argument string is a palindrome and
** false otherwise. A palindrome is a string that reads the same 
** forwards and backwards. The function should ignore all nonalphabetic 
** characters, and character comparisons should be case independent. 
*/

#include <stdio.h>

int palindrome(char* string);

int main(void)
{
    char string[100] = { "" };

    puts("Say something nice, preferably a palindrome ;-) :");
    fgets(string, 100, stdin);

    int buffer = palindrome(string);

    switch (buffer) {
    case 0:
        puts("\nNope, definetly not a palindrome!\n");

    case 1:
        puts("Nice palindrome!\n");
    }

    return 0;
}

int palindrome(char* string)
{
	char left[100] = {""};
	char right[50] = {""};
	int x, y;
	x = y = 0;

	/* 
	** Get rid of all non alpha characters
	** and get all alpha chars to have the same case
	*/
	while(*string != '\0') {
		if(*string >= 'a' && *string <='z')
			left[x++] = *string + 'a' - 'A';
		else if(*string >= 'A' && *string <= 'Z')
			left[x++] = *string;
		string++;
	}

	/* 
	** Split the left string in two equal parts. x-1 is the last char.
	** Note that we did get rid of newlines, & other non alpha chars.
	*/







	/* ****** This if - else section is bugged ************
	** I need to nul terminate the strings only when and if I finish
	** the if condition!
	** But in this implementation, even if I don't finish the if
	** they get nul terminated
	**********************************************************
	if(x % 2 == 1) {
		/*the new left string will have half of the right size
		** +1 if the buffer1 has odd number of chars */
		y = x/2 + 1;
		while(right[y++] = left[x--])
			;
	}
	left[++x] = '\0';
	right[y] = '\0'; 
	else {
		y = x/2;
		while(right[y++] = left[x--])
			;
	}












	puts("*********************************");
	printf("left - %s.\n", left);
	printf("right- %s.\n", right);
	puts("***********************************")

	return 1;

	/*
	** Split the buffer string in 2 and compare the 2 sides 
	** to have the same chars but in reverse order
	*/
}