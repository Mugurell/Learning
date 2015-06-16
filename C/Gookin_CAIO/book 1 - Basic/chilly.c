#include <stdio.h>

int main()
{
	float temp;
	for (;;)
	printf("What is the temperature outside?");
	scanf("%f", &temp);

	/*if (temp == 26)
		printf("Cu o adiere usoara a vantului e absolut perfect!");

	else if (temp >= 35)
	{
		printf("\nCaldura mon cher...\n    Ce caldura, canicula pe bune!");
		
			/* if(temp < 20) printf("\nBrrrrr..."); */
			//In loc de if fooosesti else
/*	}
	else if (temp <= 15)
	{
		printf("\nRacoare.....Brrrr");
	}
	else
	{
		printf("Numa bine...\n           Vreme frumoasa!");
	}*/
	
	
	if (temp>=24 && temp<=32)
	{
	puts("Cu o adiere usoara e vremea perfecta!");	
		}
	else
	{
		puts("E prea... Nasoala vreme ...");
		}
	
	fpurge(stdin);
	
	return (0);
}