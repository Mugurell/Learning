#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *input;
	int size;

/*Allocate "enough" memory*/
	input = (char *)malloc(4069);		//4K input buffer
	if(input == NULL)
	{
		puts("ERROR : Not enough memory");
		return 0;
	}


/*Write on that memory*/
	printf("Enter some text %c\n", 25);
	gets(input);


/*resize input buffer to save space*/
	size = strlen(input)+1;		//+1 for the null

	if(!realloc(input, size))
	{
		puts("Unable to reallocate memory");
		return 0;
	}

	puts("Memory reallocation successfull");
	printf("String is:\n\"%s\"\n", input);
	free (input);		//free returns no value
						//unlike malloc, realloc
	puts("Memory has been released!");
	printf("String now is \n\"%s\"\n", input);

	getchar();
	return 0;
}