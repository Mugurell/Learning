#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RECORDS 6

int main(void)
{
    typedef struct JB {
        char actor[25];
        struct JB* next;
    } jb;

    char *bonds[RECORDS] = {
		"Sean Connery",
		"David Niven",
		"George Lazenby",
		"Roger Moore",
		"Timothy Dalton",
		"Pierce Brosnan"
		};

    jb* current_item;
    jb* first_item;
    jb* new_item;

    int index = 0;

/* Create the first structure in the list. */
    first_item = (jb *)malloc(sizeof(jb));
    current_item = first_item;
    // Now c_i and f_i will have the same pointee!!!!!
    // When displaying the results f_i will have Sean Connery

/* Fill the structures. */
    while (1) {
        strcpy(current_item->actor, bonds[index]);
        index++;
        if (index < RECORDS) {
            new_item = (jb *)malloc(sizeof(jb));
            current_item->next = new_item;
            current_item = new_item;
        // Now c_i divorces f_i and is sharing with n_i ??
        } else {
            current_item->next = NULL;
            break;
        }
    }

/* Display the results. */
    current_item = first_item;		/* start over */
    index = 1;
    while (current_item) {
    	printf("\nStructure %d: ", index++);
    	printf("%s\n", current_item->actor);
    	current_item = current_item->next;
    	// current item o sa ajunga la NULL -> se opreste
    }

    putchar('\n');
    
    return 0;
}