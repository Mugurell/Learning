#include <stdio.h>

int
main(void)
{
	int ch;
	int brackets = 0;

	while((ch = getchar()) != EOF) {
		if(ch == '{')
			brackets++;
		if(ch == '}') {
			if(brackets == 0)
				puts("Error: Extra closing brace!");
			else
				brackets--;
		}
	}

/*
** If no more input, do a last final check
*/
	if(brackets > 0)
		printf("Error: Unmatched opening braces - %d", brackets);

	return 0;
}