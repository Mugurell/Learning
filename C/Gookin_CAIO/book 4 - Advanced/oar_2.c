#include <stdio.h>

void binString(int n);

int main(void)
{
	int twos = 1;
	int x,r;
	unsigned short int v = 0;

	for(x=0; x<16; x++)
	{
		r = v | twos;
		printf("0x%04X | %5d = 0x%04X or ", v, twos, r);
		binString(r);
		putchar('\n');
		twos +=twos;
	}

	getchar();

	return 0;
}

void binString(int r)
{
	int bin[17];
	int x, y;

	for(x=0; r>0; x++)
	{
		bin[x] = r%2;
		r >>= 1;
	}
	bin[x] = '\0';

	for(y=x-1; y>=0; y--)
		printf("%d", bin[y]);

}