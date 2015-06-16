#include <stdio.h>

int main(void)
{
	int start, finish, *examine;

//	start = 100;
//	finish = 9;

	examine = &start;
	*examine = 101;  // am initalizat variabila start 'indirectly'
	printf("%d little old ladies started the race\n", *examine);

	examine = &finish;
	*examine = 8;    // am initailizat variabila finish 'indirectly'
	printf("But only %d little old ladies finished it", *examine);

	getchar();
	return 0;
}