#include <stdio.h>

int main(void)
{
	int teeny, *t;

	teeny = 1;
	t = &teeny;

//Use and abuse the variables
	printf("Variable teeny = %d\n", teeny);
	printf("Variable t = %p\n", t);
	printf("Variable *t = %d\n", *t);

	*t = 64;
	printf("Variable teeny = %d\n", teeny);
	printf("Variable t = %p\n", t);
	printf("Variable *t = %d\n", *t);

	getchar();

	return 0;	
}
