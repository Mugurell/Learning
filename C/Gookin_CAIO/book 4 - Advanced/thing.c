#include <stdio.h>

int main(void)
{
	const char *hello = "Greetings from your Laptop!";
	// warning: When declaring a string by using a pointer,
	// you cannot modify the string !!
	char byebye[] = "So long now!";
	char *b;

	b = byebye;

//	while(putchar(*hello++))
//		;
//	putchar('\n');
	
	puts(hello);
	puts(b);

	getchar();
	return 0;
}