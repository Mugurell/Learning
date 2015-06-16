#include <stdio.h>

int *max(int, int, int);

int main(void)
{
	int a=12, b=22, c=32;

	printf("Cel mai mare numar este %c %d", 16, *max(a,b,c));

	getchar();
	return 0;
}

int *max(int a, int b, int c)
{
	int *m;

	if(a>b && a>c) m=&a;
	else if(b>a && b>c) m=&b;
	else m=&c;

	return m;
}