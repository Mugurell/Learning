#include<stdio.h>
#define SPEED_LIMIT 65
#define RATE 26
#define FIRST_TICKET 85
#define SECOND_TICKET 95
#define THIRD_TICKET 110

int main()
{
	int total, fine, speeding;

	puts("Speeding tickets:\n");

	/* first ticket */
	speeding = FIRST_TICKET - SPEED_LIMIT;
	fine = speeding * RATE;
	total = total + fine;
	printf("For going %d in a %d zone your ticket is $%d.\n", FIRST_TICKET, SPEED_LIMIT, fine);
	
		/* second ticket */
		speeding = SECOND_TICKET - SPEED_LIMIT;
	fine = speeding * RATE;
	total = total + fine;
	printf("For going %d in a %d zone your ticket is $%d.\n", SECOND_TICKET, SPEED_LIMIT, fine);

	/* third ticket */
	speeding = THIRD_TICKET - SPEED_LIMIT;
	fine = speeding * RATE;
	total = total + fine;
	printf("For going %d in a %d zone your ticket is $%d.\n", THIRD_TICKET, SPEED_LIMIT, fine);

	/* Display total */
	printf("\n\tTotal in fines: \n\t\t$%d", total);

	return (0);
}