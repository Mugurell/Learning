/* Write a program that reads from the standard input and computes the
**  percentage of chars it finds in each of the following categories: 
**			control characters 
**			whitespace characters 
**			digits 
**			lower case letters 
**			upper case letters 
**			punctuation characters 
**			non‐printable characters 
**
** The char categories are to be as they are defined for the ctype.h
** functions. Do not use a series of if statements. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
** Define a function to compute whether a character is not printable.
** This eliminates a special case for this categ in the code below.
*/
int is_not_print(int ch)
{
	return !isprint(ch);
}

/*
** Jump table of classification functions for each category.
*/

static int (*test_funct[]) (int) = {
			iscntrl,
			isspace,
			isdigit,
			islower,
			isupper,
			ispunct,
			is_not_print
};

#define N_CATEGORIES (sizeof(test_funct)) / sizeof(test_funct[0])

/*
** The name of each of the character categories.
*/
char *label[] = {
		"control",
		"whitespace",
		"digit",
		"lower case",
		"upper case",
		"punctuation",
		"non‐printable"
};

/*
** Number of chars seen in each categ. so far, and total # of chars
*/
int count[N_CATEGORIES];
int total;

int main(void)
{
	int ch;
	unsigned int category;

	/*
	** Read and process each character
	*/
	while ((ch = getchar()) != EOF) {
		total += 1;

		/*
		** Call each of the test functions with this character.
		** If true, increment the associated counter.
		*/
		for (category = 0; category < N_CATEGORIES; category += 1) {
			if (test_funct[category](ch)) 
				count[category] += 1;
			
		}
	}

	/*
	** Print the results.
	*/
	if (total == 0)
		printf("No characters in the input!\n");
	else {
		for (category = 0; category < N_CATEGORIES; category += 1) {
			printf("%3.d%% %s characters\n", 
				count[category] * 100 / total,
				label[category]);
		}
	}
	return EXIT_SUCCESS;
}
