#include <stdio.h>

int main()
{
	char ch;

	printf("Would you like me to send your password to the bad guys?\n");

	for (;;)
	{
		puts("\nEnter Yes or No: (Y/N)");

		ch = getchar();

		if (ch == 'N')
		{
			printf("Well, then:your password is safe ! \n");
		}
		else if (ch == 'n')
		{
			printf("Well, then:your password is safe ! \n ");
		}
		else if (ch == 'Y')
		{
			printf("Okay.Sending your password ! \n ");
		}
		else if (ch == 'y')
		{
			printf("Okay.Sending your password ! \n ");
		}
		else
		{
			printf("You must enter Y or N ! \n");
		}

		fpurge(stdin);			// eliminate other keys
		/*No break here. Keep looping*/
	}

	return (0);
}