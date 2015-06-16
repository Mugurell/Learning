/*
 * Write a function that reads a string from the standard input
 * and returns a copy of the string in dynamically allocated 
 * memory. The function may not impose any limit on the 
 * size of the string being read! 
*/

 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>

 #define MAX 100

 void mine(void);
 void his(void);

 int main(void)
 {
 	his();
 	
 	return 0;
}

void mine(void)
{
	char *array;
 	char ch;
 	int size = MAX;
 	int count = 0;

 	puts("Say something to be stored in a dinamic array:");
 	array = malloc(size);
 	if (array == NULL) {
 		puts("ERROR: Not enough memory");
 		return;
 	}

 	while ((ch = getchar()) != '~') {
 		count += 1;
 		if (count > size-1) {
 			size += MAX;
 			array = realloc(array, size);
 			if (array == NULL) {
		 		puts("ERROR: Not enough memory");
		 		return;
 			}
 		}
 		array[count-1] = ch;
 	}
 	*(array+count) = '\0';
 	array = realloc(array, count);

 	printf("So the dinamic array, with %d chars now contains:\n",
 		count);
 	puts(array);
 	putchar('\n');
}


void his(void) 
{
	char *array = NULL;
	char ch;
	int len = 0;
	int size = MAX;

	/* Prima data, pregateste memorie pt array */
	array = malloc(size);
	assert(array != NULL);
	
 	puts("Say something to be stored in a dinamic array:");

	/*
	** Get characters one at a time until a new line
	** or EOF is reached.
	*/
	do {
		ch = getchar();
		if (ch == '\n' || ch == EOF)
			ch = '\0';
		
		/*
		** If the string is full, make it bigegr
		*/
		if (len >= size) {
			size += MAX;
			array = realloc(array, size);
			assert(array != NULL);
		}
		array[len] = ch;
		len += 1;
	} while (ch != '\0');

	/* Acum Reek nu i-a mai dat realloc... */
	array = realloc(array, len);
	
	printf("So the dinamic array, with %d chars now contains:\n",
 		len-1);
 	puts(array);
 	putchar('\n');

}