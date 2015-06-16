#include<stdio.h>

int main()
{
	int total, fine, speeding;
	int speed_limit = 55;
	int rate = 15;
	int first_ticket = 85;
	int second_ticket = 95;
	int third_ticket = 100;

	puts("Speeding tickets:\n");

	/* first ticket */
	speeding = first_ticket - speed_limit;
	fine = speeding * rate;
	total = total + fine;
	printf("For going %d in a %d zone your ticket is $%d.\n", first_ticket, speed_limit, fine);

	/* second ticket */
	speeding = second_ticket - speed_limit;
	fine = speeding * rate;
	total = total + fine;
	printf("For going %d in a %d zone your ticket is $%d.\n", second_ticket, speed_limit, fine);

	/* third ticket */
	speeding = third_ticket - speed_limit;
	fine = speeding * rate;
	total = total + fine;
	printf("For going %d in a %d zone your ticket is $%d.\n", third_ticket, speed_limit, fine);

	/* Display total */
	printf("\n\tTotal in fines: \n\t\t$%d", total);

	return (0);
}