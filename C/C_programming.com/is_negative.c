#include <stdio.h>
#include <stdbool.h>

bool is_positive(int i);

int main(void)
{
	int nr;

	puts("Enter a number, & I'll tell you if it's pos or neg: ");
	scanf("%d", &nr);

	int buffer = is_positive(nr);
	if(buffer == 1)
		puts("\nYout number is positive");
	else
		puts("\nYour number is negative");
}

bool is_positive(int nr)
{
	if(nr < 0)
		return 0;
	else if(nr > 0)
		return 1;
	else
		puts("Cheeky! :-P");
}