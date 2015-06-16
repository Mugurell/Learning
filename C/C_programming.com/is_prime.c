#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool prime(int nr);
void v1(void);		/* Determine if the user's number is prime */
void v2(void);		/* -||- if a random number is prime */
void v3(void);		/* Determine all prime numbers to a user set limit */
void limited_primes(int lower, int upper);

int main(void)
{
	v3();

	return 0;
}


void v1(void)
{
	int nr;
	bool buffer;

	printf("Enter a number to check if it's prime: ");
	scanf("%d", &nr);

	printf("\n\t%d is ", nr);
	buffer = prime(nr);
	if(buffer == true)		
		puts("prime!\n");
	else 				
		puts("not prime!\n");
}


void v2(void)
{
	int nr; 
	bool buffer;

	srand((unsigned)time(NULL));
	nr = rand();
	printf("Let's try with a random number, say %d\n", nr);
	buffer = prime(nr);
	printf("Interestingly.. %d is ", nr);
	if(buffer == true)		
		puts("prime!\n");
	else 				
		puts("not prime!\n");
}


void v3(void)
{
	int upper, lower; 

	puts("Enter the limit between to calculate the prime numbers");
	puts("Lower limit?: ");
	scanf("%d", &lower);
	puts("Upper limit?: ");
	scanf("%d", &upper);

	limited_primes(lower, upper);
}


void limited_primes(int lower, int upper)
{
	int x, nr;

	for(nr = lower; nr<= upper; nr++) {
		if(nr == 2 || nr == 5)
			printf("\n\t%d", nr);
		else if(nr%2 == 0 || nr%5 == 0)
			continue;
		else
			for(x = 3; x < nr; x+=2)
				if(nr%x == 0) 
					x = nr;
				else
					printf("\n\t%d", nr);

	}
}


bool prime(int nr)
{
	int x;

	if(nr == 0 || nr == 1)
		return false;
	else if(nr == 2 || nr == 5)
		return true;
	else if(nr%2 == 0 || nr%5 == 0)
		return false;
	else
		for(x = 3; x < nr; x+=2);
			if(nr%x == 0)
				return false;
	return EXIT_FAILURE;
}