#include <stdio.h>

int main(void)
{
	int array [] = {1, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int x, *a;
	a = array;

	puts("The first 10 prime numbers are :\t");
	for (x = 0; x < 10; x++)
	{
		//printf("%d, ", *a++);
		// printf("%d, ", a++);    //asta printeaza adresele
		  printf("%d, ", a[x]);
		//  printf("%d, ", *(a+x));
		//printf("%d, ", array[x]);
	}
	printf("\b\b.");       //am mutat cursorul cu 2 spatii inapoi
	//spatiul in care era(space) + spatiul de dinaintea sa(comma)
	// in spatiul de dinaintea sa am bagat un punct

	getchar();

	return 0;
}