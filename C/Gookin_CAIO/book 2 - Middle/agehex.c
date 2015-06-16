/* Lingurar Petru-Mugurel 6-10-2014 */ 

#include <stdio.h>
int main()
{
	short int age;

	for (;;)
	{
		printf("\n\nPlease enter your age here : ");
		scanf("%d", &age);

		if (age == 26)
		{
			printf("\nYour hexadecimal age is .... \n\t\t....... \n%32.#x", age);
			printf("\n\n\nYour octal age is .... \n\t\t....... \n%31.#o", age);
			printf("\n\n\nYour scientific age is .... \n\t\t....... \n%32.2e(%g)\r", (float)age,
				   (float)age);
			break;
		}

		else
		{
			printf("\n \"Mugurel\" !? ....");
		}

		fpurge(stdin);
	}

	return (0);

}