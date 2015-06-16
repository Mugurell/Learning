#include <stdio.h>

void c(int times)
{
	int x = 0;
	int y = 0;

	printf("\nI'm having fun now!\n");
	while(x<=times){
		printf("Ha ha!\n");
		while(y>=0) {
			putchar(' ');
			y--;
		}
		x++;
		y = x;
	}

}