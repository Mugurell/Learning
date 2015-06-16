/*
** MS‐DOS and UNIX systems both support input/output redirection using
** this notation: 
**		$program < data > answer
**
** When this program executes, it will read its standard input from the
** file data instead of the keyboard, and it will write its standard 
** output to the file answer instead of the screen.
*/

#ifndef _stdio_h
#include <stdio.h>
#endif

int main(void)
{
	printf("Hello bha!\n");

	return 0;
}