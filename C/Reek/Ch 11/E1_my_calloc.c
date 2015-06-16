#include <stdlib.h>
#include <stdio.h>

void * calloc(size_t n_elements, size_t element_size)
{
	char *new_memory;

	n_elements *= element_size;

	new_memory = malloc(n_elements);

	if(new_memory != NULL) {
		char *ptr;
		ptr = new_memory;

		/* Fiecare bit va fi initializat cu nul */
		while(--n_elements >= 0)
			*ptr++ = '\0';
	}
	return new_memory;
}