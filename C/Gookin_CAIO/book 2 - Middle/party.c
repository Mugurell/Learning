#include <stdio.h>

int main()
{
	char party;

	printf("Which is your political party?\n");
	printf("D, I, R or something else: ");
	scanf("%c",&party);

	switch(party)
	{
		case 'd':
		case 'D':
			puts("Democratic");
			break;
		case 'i':
		case 'I':
			puts("Independent");
			break;
		case 'r':
		case 'R':
			puts("Republican.");
			break;
		default:
			puts("Something else");
	}
	return(0);
}
