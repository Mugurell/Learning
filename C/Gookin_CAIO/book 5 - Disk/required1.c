#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc>2) {
		puts("Warning\n");
		puts("Arguments limit (1) exceeded !");
	}

	return 0;
}