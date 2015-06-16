#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define 	RECORDS 	6

int main(void)
{
	typedef struct JB {
		char actor [25];
		struct JB *next;
	} jb;

	char *bonds[RECORDS] = {
		"Sean Connery",
		"David Niven",
		"George Lazenby",
		"Roger Moore",
		"Timothy Dalton",
		"Pierce Brosnan"
		};

	jb *current_item;
	jb *first_item;
	jb *new_item;

	int index = 0;

/* Create the first structure in the list. */
	first_item = (jb *)malloc(sizeof(jb));
	current_item = first_item;

/* Fill the structures. */
	while (index < RECORDS) {
		strcpy(current_item->actor, bonds[index]);
		new_item = (jb *)malloc(sizeof(jb));
		current_item->next = new_item;

		current_item = new_item;
		index++;
	}

/* Display the results. */

	return 0;
}