#ifndef _stdio_h
#include <stdio.h>
#include <ctype.h>
#endif

	/*
	** Converts a series of chars from stdin to integers
	*/
int main(void)
{
	int value = 0;
	int ch;

	/*
	** Convert digits from the standard input;
	** Stop when we get a char that is not a digit.
	*/
	while ( ( ch = getchar()) != EOF && isdigit( ch )) {
		value *= 10;
		value += ch - '0';
	}

	/*
	** Push back the nondigit so we don't lose it.
	*/
	ungetc( ch, stdin );

	return value;
}