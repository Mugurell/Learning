#include <stdio.h>
#include <string.h>

int main(void)
{
	char *nume = "Mugurel";

	char aaray[]= "John";
	nume = aaray;

	puts(nume);


	printf("1st letter of that is %s\b\b\b\b\b\b%s\n", nume, "      ");
	printf("1st letter of that is %c\n", *(nume));
	printf("2nd letter of that is %c\n", *(nume+1));
	printf("3rd letter of that is %c\n", nume[2]);
	printf("4th letter of that is %c\n", *(nume+3));
	printf("5th letter of that is %c\n", nume[4]);
	printf("6th letter of that is %c\n", *(nume+5));
	printf("7th letter of that is %c\n", nume[6]);
	printf("8th letter of that is %c\n\n", *(nume+7));



	return 0;
}