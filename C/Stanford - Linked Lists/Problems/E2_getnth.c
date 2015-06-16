// Given a list and an index, return the data
// in the nth node of the list. The nodes are numbered from 0.
// Assert fails if the index is invalid (outside 0..lengh-1).
// int GetNth(struct node* head, int index) 

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int			data;
	struct NODE *next;
} node;

int GetNth( node* head, int index);
node * build_list(void);

int main(void)
{
	node *head;
	int node_nr;

	puts("You have a structure with 5 nodes");
	printf("Which node do you wanna inspect?: ");
        scanf("%d", &node_nr);
        while(getchar() != '\n');

	head = build_list();
	printf("\nNode nr. %d contains #%d\n\n", node_nr, GetNth(head, node_nr));

	return 0;
}


node * build_list(void)
{
	node *fifth = (node *)malloc(sizeof (node));
	node *fourth = (node *)malloc(sizeof (node));
	node *third = (node *)malloc(sizeof (node));
	node *two = (node *)malloc(sizeof (node));
	node *first = (node *)malloc(sizeof (node));

	fifth->data = 55;		fifth->next = NULL;
	fourth->data = 44;		fourth->next = fifth;
	third->data = 33;		third->next = fourth;
	two->data = 22;			two->next = third;
	first->data = 11;		first->next = two;

	return first;
}


int GetNth(node* head, int index)
{
	node *current = NULL;
	node *next = head;
	int count = 0;

	while (next != NULL && count < index) {
		count++;
		current = next;
		next = current->next;
	}

	return current->data;
}

