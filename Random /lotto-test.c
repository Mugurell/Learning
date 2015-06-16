/*First of all I want to say hi to you all!

I'm a beginner programmer, started with C, and started to really enjoy this.

Today I've stumbled upon something very interesting and intriguing at the same time in one of my test programs:

*/
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

	puts("\t\tTHE AMAZING LOTTERY\n\n");
	printf("Have you ever won at a lottery?\n");
	printf("You can try your luck now! %c\n\n" , 2);
	printf("Quick, write down 6 numbers and then press \"Enter\"");
	getchar();

	for (y = 0; y < BALLS; y++)
	{


/* This is the intriguing part*/
		printf("%d\n", y);


	  label:
		z = rand() % NUMBERS+1;

		for (y = 0; y < BALLS; y++)
		{
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
	printf("\n\nToday's numbers are %c\a ", 16);
	for (x = 0; x < BALLS; x++)
		printf("%d, ", numbers[x]);

    printf("\n\n\nWell...\n\t..tough luck buddy..");
    printf("\n\n\n\tMaybe next time.. %c" , 15);
    putchar('\n');
    getchar();

	return 0;
}

/*
Why does the same variable, used twice in 2 nested loops, cand held different values without causing any problems?

*/
