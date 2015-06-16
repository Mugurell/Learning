#include <stdio.h>

int main()
{
	FILE *myfile;
	char c;

	myfile = fopen("yourname.txt", "r");
/***** If fopen returned NULL*****/
	if(!myfile) {
		puts("Some kind of a file error\n");
		return 1;
	}

/******If the file was opened successfully*******/
	while((c = fgetc(myfile)) != EOF)
		putchar(c);

	fclose(myfile);

	return 0;
}