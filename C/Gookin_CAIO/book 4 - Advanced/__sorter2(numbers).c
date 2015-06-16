#include <stdio.h>

#define SIZE 10
int main(void)
{
	int x, a, b;
	 int *list[SIZE];
	 int *sorted[SIZE];
	 int *temp;

	puts("Enter 10 random numbers to be sorted:");
	for("x=0; x<10; x++")
	{
		printf("#%2d: ", x+1);
		scanf("%d", (list+x));
		(sorted+x) = (list+x);
		putchar('\n');
	}

	for(a=0; a<SIZE-1; a++)
		for(b=a+1; b<SIZE; b++)
		{
			if(*(sorted+a) > *(sorted+b))
				*temp = *(sorted+a);
				*(sorted+a) = *(sorted+b);
				*(sorted+b) = *temp;
		}

	puts("Original list   ///   Sorted list");
	for(x=0; x<10; x++)
		printf("%10d\t%10d\n", *(list+x), *(sorted+x) );


	getchar();
	return 0;
}