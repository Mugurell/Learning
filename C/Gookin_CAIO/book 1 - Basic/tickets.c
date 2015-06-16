#include<stdio.h>

int main()
{
	int total, fine, speeding;

	puts("Speeding tickets\n");
	/* first ticket */
	speeding = 85 - 55;			/* mph over limit */
	fine = speeding * 15;         /* $ fine per mph over limit */
	total = total + fine;
	printf("For going 85 in a 55 zone your ticket is $%d\n", fine);

	/* second ticket */
	speeding = 95 - 55;			/* mph over limit */
	fine = speeding * 15;         /* $ fine per mph over limit */
	total = total + fine;
	printf("For going 95 in a 55 zone your ticket is $%d\n", fine);

	/* third ticket */
	speeding = 100 - 55;			/* mph over limit */
	fine = speeding * 15;         /* $ fine per mph over limit */
	total = total + fine;
	printf("For going 100 in a 55 zone your ticket is $%d\n", fine);
	
	/*Display total*/
	printf("\nTotal in fines %d" , total);



	return (0);
}