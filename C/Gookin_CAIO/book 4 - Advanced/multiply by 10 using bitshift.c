#include <stdio.h>

int main(void)
{
	int v, r;
	
	printf("Enter a value to be multiplied by 10 %c ", 26);
	scanf("%d", &v);

	r = (v << 1) + (v << 3);

	putchar('\n');

	printf("%d multiplied by 10 is %d.\n", v, r);

	while(getchar() != '\n')
		continue;

	return 0;
}