/*
** Read, sort and print a list of integer values
*/

#include <stdio.h>
#include <stdlib.h>

/*
** 		Function called by 'qsort' to compare integer values
*/
int compare_integers(void const *a, void const *b)
{
	register int 	const *pa = a;
	register int 	const *pb = b;

/*
** Is *pa > *pb?
**		Y:  return 1
**		N: is *pa < *pb ? 
**			Y: return -1
**			N(they are equal): return 0
*/ 
	return *pa > *pb ? 1 : *pa < *pb ? -1 : 0;
}

int main(void)
{
	int *array;
	int n_values;
	int i;

	/*
	** See how many numbers there will be.
	*/
	printf("How many numbers are there? ");
	if(scanf("%d", &n_values) != 1 || n_values <= 0) {
		printf("Illegal number of values.\n");
		exit(EXIT_FAILURE);
	}

	/*
	** Get memory to store them.
	*/
	array = malloc(n_values * sizeof(int));
	if(array == NULL) {
		printf("Can't get memory for that many values.\n");
		exit(EXIT_FAILURE);
	}

	/*
	** Read the numbers.
	*/
	for(i = 0; i<n_values; i++) {
		printf("? ");
		if(scanf("%d", array+i) != 1) {
			printf("Error reading value #%d\n", i);
			free(array);		/* to fix memory leak */
			exit(EXIT_FAILURE);
		}
	}	

	/*
	** Sort the values.
	*/
	qsort(array, n_values, sizeof(int), compare_integers);

	/*
	** Print them out.
	*/
	for(i = 0; i < n_values; i +=1)
		printf("%d\n", array[i]);

	/*
	** Free the memory and exit.
	*/
	free(array);
	return EXIT_SUCCESS;
}