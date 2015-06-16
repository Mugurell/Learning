

#include <stdio.h>
#define NDEBUG
#include <assert.h>



int main(void)
{
	int i = 9;
	assert(i == 8);
	puts("\nNu  a mai ajuns aici!");
	perror("heroare");

	return 0;
}