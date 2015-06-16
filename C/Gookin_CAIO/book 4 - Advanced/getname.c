#include <stdio.h>

int main(void)
{
	char *n, name[100];
	n = name;

	printf("What is you name, dear Sir? %c", 16);
	fgets(n, 100, stdin);		//puteam sa pun si name
//	gets(n);

//	printf("So your name is..");
//	puts(n);					//puteam sa pun si name

	printf("\nSo youre name is ");
	while(putchar(*n++))
		;
	printf("..\n\tCool name!");

	getchar();
	return 0;
}