#include <stdio.h>

int main(void)
{
	const char *seven[] = {
		"bashful",
		"doc",
		"dopey",
		"grumpy",
		"happy",
		"sneezy",
		"sleepy"
	};
	int x, c;

/*
	for(x=0; x<7; x++)
	//	printf("\t%s\n", seven[x]);			//array notation
		printf("\t%s\n", *(seven+x));		//pointer notation
*/




/***Display only the first 3 letters of every name********
	for(x=0; x<7; x++)
	{
		for(c=0; c<7; c++)
			//printf("%c", seven[x][c]);	//array notation
			printf("%c", *(*(seven+x)+c));	//pointer notation
		putchar('\n');
	}
**********************************************************/




//***Display the entire strings using *(*(string+a)+b)*******
//		which is the pointer notation
	for(x=0; x<7; x++)
	{
		c = 0;
		putchar('\t');
		while(putchar(*(*(seven+x)+c++)))
			;
		putchar('\n');
	}

	getchar();
	return 0;
}