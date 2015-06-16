#include <stdio.h>

int age;

int main(void)
{
	puts("\n");

	printf("Enter our age in years %c ", 16);
	scanf("%d", &age);
	
	show();

	while(getchar() != '\n')
		continue;
	getchar();
	return 0;
}