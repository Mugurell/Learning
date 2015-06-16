#include <stdio.h>

int main()
{
	int profits, profits3;
	int expenses = 27;
	int income = 120;

	profits = income - expenses;
	profits3 = (income - expenses) * 3;

	printf("Garage sale profits were $%d.", profits);
	printf("\nTriple profits would have been $%d.", profits3);

	return (0);
}