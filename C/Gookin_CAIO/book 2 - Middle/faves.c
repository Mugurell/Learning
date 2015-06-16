#include <stdio.h>

int main()
{
	char letter,number;
	printf("What is your favourite letter? ");
	letter=getchar();
	fflash (stdin);         /*fflush(stdin) for windows*/
	printf("What is your favourite number? ");
	number=getchar();
	printf("\n\n  Thank you!\n\n  So \"%c\" is your favourite letter and \"%c\" is your favourite number....\n \n\n    Nice!\n" , letter , number);
	return(0);
	}
