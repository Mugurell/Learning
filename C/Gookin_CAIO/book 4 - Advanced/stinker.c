#include <stdio.h>

int main(void)
{
	char *s, string[] = "Is it supposed to smell that way?";

	s = string;

	while (putchar(*s++))      /*null char is 0 , interpreted as false*/
		;					   /*  so the counting stop at 0*/

	getchar();
	return 0;
}