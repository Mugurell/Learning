/*
** Add a node/more nodes after the last one in the list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE *next;
} node;

void insert(node **head_ref, int num);

int main(void)
{
	node *three = &(node) {30, NULL};
	node *two = &(node) {20, three};
	node *head = &(node) {10, two};
	node *head_bak = head;

	int i = 0;

	puts("So, our original linked list is:");
	while (head != NULL) {
		i++;
		printf("\tNode %d - %d\n", i, head->data);
		head = head->next;
	}
	head = head_bak;

	 for (i = 1; i < 50; i+=11)
		insert(&head, i);
	puts("\nAnd after some twickling it now is..:");
	i = 0;
	while (head != NULL) {
		i++;
		printf("\tNode %d - %d\n", i, head->data);
		head = head->next;
	}
	putchar('\n');

	return 0;
}

void insert(node **head_ref, int num)
{
	node *current = *head_ref;
	node *previous = NULL;
	node *new;

	while (current != NULL && current->data < num) {
		previous = current;		// this is the last node without NULL
		current = current->next;
	}

	new = (node *)malloc(sizeof(node));

	new->data = num;
	new->next = current;

	/* 
	** Insert the new node after previous but before current.
	*/
	if (previous == NULL)
		*head_ref = new;
	else
		previous->next = new;

}