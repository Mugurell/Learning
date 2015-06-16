#ifndef _stdlib_h
#include <stdlib.h>
#include <stdio.h>
#endif

int main(void)
{
	int i;

	srand(19034525245636);

	for(i = 0; i < 100; i ++)
		printf("%d\n", rand() %1000);
}