// #include <stdio.h>  nu facem nicio operatiune io
#include <stdlib.h>

int main(void)
{
	int number;
	int divisor;

	/*
	** One and two are easy
	*/
	printf("1\n2\n");

	/*
	** No other numbers are prime.
	** Look at the remaining odd ones.
	** (the even obviously are divided by 2)
	*/
	for(number = 3; number <= 100; number +=2) {
		/*
		** See if any divisor from 3 up to the number
		** evenly divide the number
		*/
		for(divisor = 3; divisor < number; divisor += 2)
			if(number % divisor == 0)
				break;		//break from the small for

		/*
		** If the loop above stopped because the divisor got too big,
		** we've got a prime!
		*/
		if(divisor >= number)
			printf("%d\n", number);
	}

	return 0;
}
