#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc == 1n)
	{
		puts("No name specified!");
		return(1);
	}
	printf("Is your name %s?\n",argv[1]);
	return(0);
}

