#include <stdio.h>

int main(void)
{
	char ch;

	while ((ch = fgetc(stdin)) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
			ch += 'A' - 'a';
		fputc(ch, stdout);
	}

	return 0;
}