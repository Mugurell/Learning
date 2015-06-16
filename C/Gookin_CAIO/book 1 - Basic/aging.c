#include <stdio.h>

int main()
{

	int age;

	printf("Please enter your age :");
	scanf("%d", &age);

	printf("Today you are %d years old. \n", age);
	printf("In twenty  years from now you will be %d years. \n", age += 25);
	// age=+25 memora 25 in age ( + unary )

	if (age > 100)
		printf
			("\nDon' really think you would get up to %d....\n\t Unfortunately you would prohably be dead long before %d",
			 age, age);

	return (0);

}