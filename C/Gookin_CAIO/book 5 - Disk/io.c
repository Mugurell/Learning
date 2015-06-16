#include <stdio.h>

int main(void)
{
	char ch;
	
	while((ch = fgetc(stdin)) != EOF)
		fputc(ch, stdout);
// EOF (end-of-file character) e definit in stdio.h
// In windows e de fapt Ctrl+Z(and Enter)
// In UNIX de cele mai multe ori e Ctrl+D

	getchar();
	return 0;
}