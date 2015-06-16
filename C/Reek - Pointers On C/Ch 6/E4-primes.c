/*
** Sieve of Erastosthenes -- compute prime numbers using an array
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

#define TRUE  1
#define FALSE 0

int main()
{
	char	sieve[SIZE];	/* the sieve */
	char	*sp;			/* pointer to access the sieve */
	int		number;			/* number we're computing */

	/*
	** Set the entire sieve to TRUE.
	*/
	for(sp = sieve; sp < &sieve[SIZE];)
		*sp++ = TRUE;

	/*
	** Process each number from 3 to as many as the sieve holds.
	** (NOTE: the loop is terminated from inside.)
	*/
	for(number = 3; ; number +=2) {
		/*
		** Set the pointer to the proper element in the sieve
		** and stop the loop if we've gone too far.
		*/
		sp = &sieve[0] + (number - 3)/2;
		if(sp >= &sieve[SIZE])
			break;

		/*
		** Now advance the pointer by multiplies of the number
		** and set each subsequent entry FALSE
		*/
		while(sp += number, sp < &sieve[SIZE])
			*sp = FALSE;
	}

	/*
	** Go through the entire sieve now and print the numbers 
	** coresponding to the locations that remained TRUE
	*/
	printf("2\n");
	for(number = 3, sp = &sieve[0];
		sp < &sieve[SIZE];
		number +=2, sp++) {
			if(*sp)
					printf("%d\n", number);
	}

	return EXIT_SUCCESS;
}