#include <stdio.h>

int main(void)
{
	short int array[] = { 2, 3, 5, 7, 9 };
	short int *pa;		//trebuie ca pointerul sa fie de exact aceeasi fel
						// daca puneam doar int *pa => warniing
	int x;

	pa = array;
	for(x=0; x<5; x++)
	{
	//	pa = &array[x];
		printf("array[%d] at %p = %d\n", x, pa, *pa);
		printf("array[%d] at %p\n", x, pa);
		pa++;
	}

	getchar();

	return 0;
}
