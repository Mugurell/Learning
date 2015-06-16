#include <stdio.h>

int main()
{
	char prenume[20];
	char preprenume[20];
	char nume[3];
	puts("  What's your name?");
	gets (prenume);
	puts("\n  That is not your full name..., is it?");
	puts("  What's your other name?");
	gets(preprenume);
	puts("\n  And your last name!\n    Do I have to guess?");
	gets(nume);
	printf("\n\n   Nice to meet you %s %s-%s !\n" , nume,preprenume,prenume);
	return(0);	
}