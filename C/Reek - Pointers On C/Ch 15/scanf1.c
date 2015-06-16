/*
** Line-oriented input processing with scanf
*/

#ifndef _stdio_h
#include <stdio.h>
#endif

#define 	BUFFER_SIZE 	100 /* Longest line we'll handle */
void function (FILE *input);

int main(void)
{
	FILE *input;
	printf("23 in hexa %#perrorX.\n", 23);
	printf("Enter 4 numbers to be scanned:\n");
	input = fopen("4nre.txt", "r");
	if (input == NULL) {
		perror("heroare");
	}
	function(input);



	return 0;
}

void function (FILE *input)
{
	int a, b, c, d, e;
	char buffer[BUFFER_SIZE];

	while (fgets(buffer, BUFFER_SIZE, input) != NULL) {
		if (sscanf(buffer, "%d %d %d %d %d", &a, &b, &c, &d, &e) != 4) {
			fprintf(stderr, "Bad input skipped: %s", buffer);
			continue;
		}
		/*
		** Process this set of input
		*/
	}
}