/*
** Insert into an ordered, singly linked list.
** The arguments are a pointer to the first node in the list,
** and the value to insert.
*/

#include <stdio.h>
#include <stdlib.h>

#define 	FALSE	0
#define 	TRUE	1

typedef struct NODE {
	struct NODE *link;
	int value;
} node;

int insert1(node **link_p, int new_value);

int main(void)
{
	node *three = &(node) {NULL, 33};
	node *two = &(node) {three, 22};
	node *head = &(node) {two, 11};

	node *head_backup = head;
	int i = 0;

	puts("So, the original linked list is:");
	while (head != NULL) {
		i++;
		printf("\tNode %d - %d\n", i, head->value);
		head = head->link;
	}
	head = head_backup;

	/*
	** Now call the insert1 function to insert another node.
	** If it succedes it will return 1 - TRUE.
	*/
	i = insert1(&head, 3);
	if (i == TRUE) {
		i = 0;
		puts("\nAfter some twickling around, the new list contains..");
		while (head != NULL) {
			i++;
			printf("\tNode %d - %d\n", i, head->value);
			head = head->link;
		}
	} else {
		puts("And that's all folks !..");
		puts("Read: Couldn't introduce another node into the list\n");
	}

	return 0;
}

int insert1(node **link_p, int new_value)
{
	node *current = *link_p;
	node *new;

	/* Look for the right place by walking down the list until we reach
	** a node whose value is greater than or equal to the new value.
	*/
	while (current != NULL && current->value < new_value) 
		link_p = &current->link;
	/* Cand termina while-ul, link_p o sa fie node-ul mai mic
	 * si current o sa fie node-ul mai mare.
	 * Urmeaza sa bagi un nou nod intre astea doua. */

	/*
	** Allocate a new node and store the new value into it.
	** In this event, we return FALSE.
	*/
	new = (node *)malloc(sizeof(node));
	if (new == NULL)
		return FALSE;
	new->value = new_value;

	/*
	** Insert the new node into the list (after previous
	** but before current) and return TRUE.
	*/
	new->link = current;
	*link_p = new;

	return TRUE;
}

