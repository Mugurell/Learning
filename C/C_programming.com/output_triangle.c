#include <stdio.h>

int main(void)
{
	int x, y, n;

	puts("The story says:");
	printf("\tWrite a function that outputs a right-side-up triangle");
	printf("\n\tof height n and base width 2n-1\n\n");

	printf("So, how big should your triangle be? - ");
	scanf("%d", &n);
	if (n > 10)
		puts("Uhmm.. Sometimes too big is just too big!!..\n\n");
	else {
		for(y = 1; y <=n; y++) {
			for(x = 0; x < n-y; x++)	putchar(' ');
			for(x=(n-y); x<(n-y)+(2*y-1); x++) 		putchar('*');
			putchar('\n');
		}
	}

	return 0;
}