#include <stdio.h>

int main()
{
	int agent;
	char code;

	printf("Enter your agent number: ");
	scanf("%d", &agent);
	fpurge(stdin);

	printf("Enter your single-digit code key: ");
	scanf("%ch", &code);

	if (agent == 7 && code == 'B' || code == 'b')
	{
		puts("Welcome aboard, James Bond!");
		puts("You may commence with operation \"FreeCell\"");
	}
	else
	{
		puts("The authorities have been notified by this illegal access");
	}

	return (0);
}