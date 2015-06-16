#include <stdio.h>

int main()
{
	int number;
	float iq;
	char first;

	puts("IQ Calculator\n");

	printf("Enter your house or apartment number:");
	scanf("%d", &number);
    fpurge(stdin);

	printf("Enter the first letter of your last name:");
	scanf("%c", &first);

	puts("\n\n\tCalculating your IQ.... \n\t\t......");

	iq = (float)number / first;

	if (iq <= 50)
		iq = iq * 2;
	if (iq > 50 && iq < 80)
		iq = iq + 50;

	printf("Your IQ is probably ... %f\r", iq);

	return (0);
}