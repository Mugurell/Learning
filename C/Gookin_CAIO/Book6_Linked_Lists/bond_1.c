#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	typedef struct JB{
		char actor[25];
		struct JB *next;
	} jb;		// daca vroiam variabila puneam virgula nainte

	jb *bond;

	/*
	** Create the first structure in the list.
	*/
	bond = (jb *)malloc(sizeof(jb));

	/*
	** Fill the structure.
	*/
	// strcpy(bond->actor, "Sean Connery");
	// bond->next = NULL;		/* End of list.*/
	 *bond = (jb) {"Sean Connery", NULL};

	/*
	** Display the results.
	*/
	printf("\nThe first structure has been created:\n");
	printf("\tbond->actor = %s\n", bond->actor);
	printf("\tnext structure's adress = %p\n\n", bond->next);

	return 0;
}