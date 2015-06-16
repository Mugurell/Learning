#include <stdio.h>

int main(void)
{
	int ch;
	int line = 0;
	int at_beginning = 1;

/*
** Read chars and process 'em one by one.
*/
	while((ch = getchar()) != EOF) {
		/*
		** If we're at the beginning of a line,
		** print the line number
		*/
		if(at_beginning == 1) {
			at_beginning = 0;
			printf("Line %d: ", ++line);
		}
		/*
		** Print the character, and check for end of line.
		*/
		putchar(ch);
		if(ch == '\n')
			at_beginning = 1;
	}
	return 0;
}