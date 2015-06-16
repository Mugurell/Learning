#include <stdio.h>

int main(void)
{
	float a, b, c, temp;

	puts("Enter the lenghts of the 3 sides of a triangle:");
	scanf("%f %f %f", &a, &b, &c);

	/*
	** Sort the values
	** a <= b <= c
	*/

	if(a > b) {
		temp = a;
		a = b;
		b = temp;
	}
	if(a > c) {
		temp = a;
		a = c;
		c = temp;
	}
	if(b > c) {
		temp = b;
		b = c;
		c = temp;
	}
	/*
	** See what kind of a triangle it is
	*/
	if (a <= 0 || a+b < c)
		printf("Not a triangle!\n\n");
	else if (a == b && b == c)
		printf("You've got an equilateral triangle!\n\n");
	else if (a==b || b==c)
		printf("You've got an isosceles triangle\n\n");
	else
		printf("You've got an scalene triangle!\n\n");
	
	return 0;
}