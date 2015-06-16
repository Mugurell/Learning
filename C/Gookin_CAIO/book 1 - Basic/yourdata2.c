#include<stdio.h>

int main()
{
	char input[20];
	int age;
	float height;;

	printf("Enter your age in years please :");
	scanf("%i", &age);

	int months = age * 12;

	printf("Enter your height in cm please :");
	scanf("%f", &height);
	float inches = height * 0.3937;

	printf("\n\nWith the great power invested in me I can tell you"
		   "\n (show it on the screen)"
		   "\n... that you are %i years (which would mean %i months)"
		   "\n                 and %.f cm in height (which would mean %.3f inches)!", age, months,
		   height, inches);

	printf("\n\nAge\tHeight(cm)");
	printf("\n%i\t%.f", age, height);
	printf("\nMonths\tInches");
	printf("\n%i\t%.3f", months, inches);
	return (0);
}