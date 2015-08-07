/*********************************************
* Exercise 1-17.
* Write a program to print all input lines
* that are longer than 80 characters.
* *******************************************/

#include <stdio.h>

#define MAXIMUM 20

void comparison(char[], int);
void print_prop(int, int, char[]);

int main()
{
	char prop[1000];

	printf("\tStory says you must say something on more lines\nand I'll printf all the lines that are over %d characters.\n", MAXIMUM);
	puts("So let's get to it!\n");

	comparison (prop, MAXIMUM);

	while(getchar() != '\n')
		continue;

	getchar();

	return 0;
}




void comparison(char prop[], int max)
{
	int x = 0;
	char c;

	for (;;)
	{
		c = getchar();

		if (c == '~')
		{
			prop[x] = '\0';     //null character ca doar e string
			print_prop(x, max, prop);
			puts("\nSo.. do you wanna stop?\n\tOkey...");
			break;
		}
		else if (c == '\n')
		{	prop[x] = '\0';     //null character ca doar e string
			print_prop(x, max, prop);
			x = 0;
		}
		else
			prop[x++] = c;
	}

	//  while ((prop[x++] = getchar()) != '~')
	//      ;

}



/* Didn't skipped the props with <80 chars
** for testing purposes
*/
void print_prop(int x, int max, char prop[])
{
	if ((x - 1) > max)
		printf("You said\n%s", prop);
	else 
		puts("Not enough characters");
}
