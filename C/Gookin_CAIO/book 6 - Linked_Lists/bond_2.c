#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main(void)
{
	typedef struct JB {
		char actor[25];
		struct JB *next;
	} link_to;

	link_to *first_item;
	link_to *current_item;
	link_to *new_item;

/* Create the first structure in the list. */
	first_item = (link_to *)malloc(sizeof(link_to));
	assert(first_item != NULL);

/* Fill the first structure. */
		/*
		** Daca as face asa primesc warninguri pt empty braces.
		*/
		// *first_item = (link_to) {"Sean Connery"};
		// new_item = (link_to *)malloc(sizeof(link_to));
		// assert(new_item != NULL);
		// *first_item = (link_to) {{}, new_item};
	strcpy(first_item->actor, "Sean Connery");
	new_item = (link_to *)malloc(sizeof(link_to));
	assert(new_item != NULL);
	first_item->next = new_item;

/* Fill the second structure. */
	current_item = new_item;
	strcpy(current_item->actor, "David Niven");
	current_item->next = NULL;

/* Display the results. */
	printf("\nThe first structure:\n");
	printf("\tfirst_item->actor = %s\n", first_item->actor);
	printf("\tnext structure adress = %p\n", first_item->next);

	printf("\nThe second structure:\n");
	printf("\tcurrent_item->actor = %s\n", current_item->actor);
	printf("\tnext structure adress = %p\n", current_item->next);

	return 0;
}