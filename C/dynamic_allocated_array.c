#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

#define MAX 20

void ints(void);
void chars(void);
void delays(void);

int main(void)
{
	char ch;

	puts("\nWould you like to create a dinamically allocated");
	printf("array for chars[C] or for ints[I] ?: ");
	ch = getchar();
	if (ch > 'a' && ch < 'z')
		ch += 'A' - 'a';

	switch (ch) {

		case 'C':
			printf("\nOk\nHere it comes\n\t");
			delays();
			chars();
			break;
		case 'I':
			printf("\nOk\nHere it comes\n\t");
			delays();
			ints();
			break;
		default:
			puts("Guess you wanna exit..\n\t Bye!\n");
			break;
	}

}
void delays(void)
{
	sleep(1);
	printf("\t...\t");
	sleep(1);
	puts("...");

}

void ints(void)
{

	int *array;
	int value;
	int count = 0;
	int size = MAX;

	puts("Enter some numbers, separated by spaces,");
	puts("to store in a dinamically allocated array:");

	array = (int *)malloc(size * sizeof(int));
	assert(array != NULL);

	while (scanf("%d", &value) == 1) {
		count += 1;
		if (count > size) {
			size += MAX;
			array = realloc(array, size * sizeof(int));
			assert(array != NULL);
		}
		array[count-1] = value;
	}
	if (count < size) {
		array = realloc(array, count * sizeof(int));
		assert(array != NULL);
	}
	printf("So you had %d numbers:\n", count);
	value = 0;
	while(value++ < count)
		printf("%d, ", *array++);
	printf("\b\b.\n");
}

void chars(void)
{
	char *array;
	char ch;
	int len = 0;
	int size = MAX;

	puts("Write anything you like and it will be automagically");
	puts("stored into a dinamically allocated array.");
	puts("Press '~' to stop.");
	array = malloc(size);
	assert(array != NULL);

	do {
		ch = getchar();
		if (ch == '~' || ch == EOF)
			ch = '\0';

		len += 1;

		if (len > size) {
			size += MAX;
			array = realloc(array, size);
			assert(array != NULL);
		}
		array[len-1] = ch;
	} while (ch != '\0');

	if (len < size) {
		array = realloc(array, len);
		assert(array != NULL);
	}

	delays();
	puts("So you wrote..:");
	delays();
	puts(array);
}