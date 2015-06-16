#include <stdio.h>

int main(void)
{
	const char *strings[] = {"Type something", 
					  "C:\\>",
					  "."};
	puts(strings[0]);
	puts(strings[1]);
	puts(strings[2]);
	

	getchar();
	return 0;
}