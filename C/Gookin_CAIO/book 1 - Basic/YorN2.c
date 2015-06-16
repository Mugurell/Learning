#include <stdio.h>

int main()
{
	char ch;

	puts("Would you like me to send your password to the bad guys?");

	for (;;)
	{
		printf("Enter Yes or No (Y or N)?");
		ch = getchar();
		if (ch == 'N' || ch == 'n')
		{
			puts("Well then, your password is safe!");
			break;
		}
		
		else if (ch == 'Y' || ch == 'y')
		{

			puts("Okay, sending password...");
			break;
		}

		else
		{
			puts("You must enter Y or N! \n");
		}

		fpurge(stdin);
		/* no brake here, keep looping */
	}
	return (0);
}