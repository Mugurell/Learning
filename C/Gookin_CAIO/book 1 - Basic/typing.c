#include<stdio.h>

int main()
{
	char ch;
	puts("Typing program...");
	puts("Type away");

	for (;;)
	{
		ch = getchar();
	// scanf("%c" , &ch);
		if (ch == 'h' || ch =='H')
		{
			break;
		}
	}
	return (0);
}