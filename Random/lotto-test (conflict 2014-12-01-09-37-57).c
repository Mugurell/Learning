//First of all I want to say hi to you all!

//I'm a beginner programmer, started with C, and started to really enjoy this.

//Today I've stumbled upon something very interesting and intriguing at the same time in one of my test programs:


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMBERS 6
#define BALLS 6

int main()
{
	int x, y, z, numbers[BALLS];
	for (x = 0; x < BALLS; x++)
		numbers[x] = -1;

	srand((unsigned)time(NULL));
	puts("THE AMAZING LOTTERY");

	for (y = 0; y < BALLS; y++)
	{

		// here comes the intriguing part
		printf("%d\n", y);


	  label:
		z = rand() % NUMBERS;

		for (y = 0; y < BALLS; y++)
		{
			// z=random()%NUMBERS;
			if (z == numbers[y])
				goto label;
			else if (numbers[y] != -1)
				continue;
			else
			{
				numbers[y] = z;
				break;
			}
		}
	}
	printf("Today's numbers are : %c", 36);
	for (x = 0; x < BALLS; x++)
		printf("%d, ", numbers[x]);

	return 0;
}


//Why does the same variable, used twice in 2 nested loops, cand held different values without causing any problems?
