#include <stdio.h>

int main()
{
	char fav;
	int num;

	printf("Enter your favourite letter character :");
	fav = getchar();
	 if (fav == 'q')
	{
		printf("That's my favourite character too!");
	}

    fpurge (stdin);
	printf("\n\nOk, wo now what is your favourite number?");
	num = getchar();
	if (num == 4)
	{
		printf("That' my favourite number!");
	}
	return (0);
}