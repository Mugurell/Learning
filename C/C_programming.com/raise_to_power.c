#include <stdio.h>

int power(int, int);

int main(void)
{
	int nr, putere;
	puts("\nEnter a number: ");
	scanf("%d", &nr);
	puts("That will be raised to what power?: ");
	scanf("%d", &putere);

	printf("\n\t%d ^ %d = %d\n\n", nr, putere, power(nr, putere));

	return 0;
}

int power(int nr, int putere)
{
	int result = 1;

	if(putere == 0)
		return 1;
	else 
		for(int x = 0; x < putere; x++) 	
			result *= nr;

	return result;
}