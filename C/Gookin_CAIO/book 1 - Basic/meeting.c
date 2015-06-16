#include <stdio.h>

int main()
{
	char name[20];
	puts("  What's your name?");
	gets (name);
	printf("\n\n   Nice to meet you %s !\n" , name);
	return(0);
	
	}