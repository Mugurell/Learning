#include <stdio.h>

int main(void)
{
	int ch;

	while((ch = getchar()) != EOF) {
		if(ch >= 65 && ch <= 90)
			ch += ('a' - 'A');
		 putchar(ch);
	}

	return 0;
}