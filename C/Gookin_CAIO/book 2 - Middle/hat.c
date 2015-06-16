#include <stdio.h>
#include <stdlib.h>

int main()
{
	long int hat;
	
	hat = random();        //alt: use rand()
	
	printf("%d is a random number" , hat);
	
	return 0;
	}