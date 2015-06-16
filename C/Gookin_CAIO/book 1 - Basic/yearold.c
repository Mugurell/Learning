#include <stdio.h>

int main()
{
	int age;

	printf("Enter your age in years please.");
	scanf("%d", &age);
	printf("You are %d age.", age);
	age++;
	 printf("In one year you will be %d.", age);

	return (0);
}