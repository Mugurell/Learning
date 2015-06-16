#include <stdio.h>

int main()
{
	FILE *myfile;
	char c;

	myfile = fopen("consume.c" , "r");
	if(!myfile) {
		puts("Some kind of a file error\n");
		return 1;
	}

	while((c=fgetc(myfile)) != EOF)
		fputc(c, stdout);

	fclose(myfile);

	return 0;

}