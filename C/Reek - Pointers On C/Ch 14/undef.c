/*
*********************** #undef *************************
** This directive un‐#defineʹs a name by removing its definition. 
** 		#undef	name
** If an existing name is to be redefined, the old definition must 
** first be removed with #undef. 
*/

#include <stdio.h>

#define NAME "Gogu"
#undef  NAME
#define NAME "Ana"

int main(void)
{
	printf("Numele este %s\n", NAME);

	return 0;
}