#include <stdio.h>

int *ptr2i;
char *ptr2c;

int main(void)
{
	puts("\nThe default value for a static declared pointer is..");
	printf("\t Int pointer - %p: %d\n", &ptr2i, ptr2i);
	printf("\tChar pointer - %p: %c\n", &ptr2c, ptr2c);

	return 0;
}