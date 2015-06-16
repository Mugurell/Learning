#include <stdio.h>
#define ROLL 35000
#define SPACES 40

int main()
{
	short int dice;
	long int money = 0;

	puts("Monopoly money calculator\n");

	for (dice = 0; dice < ROLL; dice += SPACES)
	{
		money += 200;
		printf("Roll %d\r", dice);	/* Display on one line */
	}

	puts("\n");

	printf("You have made a total of $%d!\n", money);

	return (0);
}