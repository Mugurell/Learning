#include <stdio.h>

int main()
{
	int age;

	for (;;)
	{

		puts("Please enter your age");
		scanf("%d", &age);

		if (age < 18 || age > 65)
		{
			puts("\tEnjoy life while you can\n\n!");
		}
		else
		{
			puts("\tGet back to work!\n\n");
		}
		fpurge(stdin);
	}


	return (0);
}