#include <stdio.h>
#include "cmplib.h"

#define SIZE 10

int main()
{
	char input[SIZE][64];
	char *isort[SIZE];
	char *temp;
	int x, a, b;

/*Get the SIZE number of strings*/
	printf("Enter %d types of fruits:\n", SIZE);
	for(x=0; x<SIZE; x++)
	{
		printf("#%d: ", x+1);
		gets(input[x]);
		isort[x] = input[x];
	}

/*Sort the strings via pointers*/
	for(a=0; a<SIZE-1; a++)
		for(b=a+1; b<SIZE; b++)
			if(c_insensitive(isort[a], isort[b]) > 0)
			{
				temp = isort[a];
				isort[a] = isort[b];
				isort[b] = temp;
			}

/*print the results*/
	printf("\n\nSorted list:\tOriginal list:\n");
	for(x=0; x<SIZE; x++)
		printf("%12s\t%12s\n", isort[x], input[x]);

	while(getchar() != '~')
		continue;
	getchar();
	return 0;
}