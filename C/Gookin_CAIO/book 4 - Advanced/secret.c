#include <stdio.h>
#include <string.h>

int main(void)
{
	char input[64];
	int len, x;

	printf("Enter tonight's pswd %c ", 26);
	gets(input);

	len = strlen(input);


	for(x=0; x<len; x++)
		input[x] = 0x7FB ^ input[x];
	puts("\n\nPress Enter to see the encrypted text");
	getchar();
	putchar('\t');
	for(x=0; x<len; x++)
		putchar(input[x]);


	for(x=0; x<len; x++)
		input[x] = 0x07FB ^ input[x];
	puts("\n\nPress Enter to see the recovered text");
	getchar();
	putchar('\t');
	for(x=0; x<len; putchar(input[x++]))
		;

	getchar();

	return 0;
}