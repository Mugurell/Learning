#ifndef _stdio_h
#include <stdio.h>
#endif

int main(void)
{
	FILE *input;

	input = fopen( "data3.txt", "r");
	if ( input == NULL ) {
		perror( "heroare:" );
		return 1;
	}
	return 0;
}