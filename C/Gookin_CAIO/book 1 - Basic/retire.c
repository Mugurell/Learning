#include <stdio.h>

int main()
{
	int age;
	printf("How old are you?");
	scanf("%d", &age);

	if (age > 64)
	{
		printf("You're %d old?\n", age);
		printf("How's your retirement going?\n");
	}
	else
	{
		printf("    Baga mare!\n       Traieste-ti viata!\n              MAXIM !!! ");
	}
	return (0);
}