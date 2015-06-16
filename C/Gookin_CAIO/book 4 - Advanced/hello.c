#include <stdio.h>

int main(void)
{
	char array[] = "Hello\n";
	char *a, *e;
	int x;

	puts(array);

	a = array;

	printf("Array 'array' is %d bytes long at %p.\n\n\n", sizeof(array), a);


	for (x = 0; x < sizeof(array); x++)		//numara si 'n' si null
	{
		e = &array[x];
		printf("Letter %d of the array is %c.\n\t", x, *e);
		printf("It is %d bytes long at %p.\n", sizeof(array[x]), e);
	}

	getchar();

	return 0;
}