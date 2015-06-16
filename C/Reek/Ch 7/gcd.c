/*
** Write a function called gcd that takes two integer arguments and returns
**the greatest common divisor of those numbers. If either of the arguments
**is not greater than zero, your function should return zero.
*/

#include <stdio.h>		/* printf, puts, etc */
#include <stdlib.h>		/* srand, rand */
#include <time.h>		/* time */

#define		MAXIMUM 	100

int gcd(int nr1, int nr2);

int
main(void)
{
	srand((unsigned)time(NULL));
	int nr1 = rand()%MAXIMUM;
	int nr2 = rand()%MAXIMUM;
	int temp;

/*
** Make sure the numbers are not equal
** and that the first nr is bigger than the second
*/
	while(1) { 
		if(nr1 == nr2) {
			nr2 = rand()&MAXIMUM;
			continue;		/* continue -> restarts from the top */
		}
		else if(nr2 > nr1) {
			temp = nr2;
			nr2 = nr1;
			nr1 = temp;
			break;
		}
		else				/* if nr1 is > nr2 move along */
			break;
	}

	puts("\n\tGreatest common divisor program\n");
	puts("So let's say we have 2 numbers..");
	printf("\t%d  and  %d\n", nr1, nr2);
	puts("Their greatest common divisor would be...");
	printf("\t    %d\n\n", gcd(nr1, nr2));

	return 0;
}

int
gcd(int nr1, int nr2)
{
	int rest;

	/*
	** If either of the arguments is not greater than zero,
	** your function should return zero.
	*/
	if(nr1 == 0 || nr2 == 0)
		return 0;

	if(nr1%nr2 == 0)
		return nr2;
	else {
		rest = nr1%nr2;
		return(gcd(nr2, rest));
	}
}