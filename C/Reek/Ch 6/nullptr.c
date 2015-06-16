/* It is illegal to dereference a NULL pointer.
Before dereferencing a pointer, you must first 
make sure that it is not NULL. 

The Standard defines a NULL pointer as a pointer value
that does not point to anything at all. 
To make a pointer variable NULL you assign it the value zero,
& to test if a pointer variable is NULL you compare it to zero. */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ptr = NULL;

	if(ptr == 0)
		printf("Ptr e 0");

	return 0;
}
