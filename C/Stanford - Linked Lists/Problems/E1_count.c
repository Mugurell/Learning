#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int			data;
	struct NODE *next;
} node;

node * build_list(void);
int count(int searched_number);

int main(void)
{
	int nr;
	int node_nr = 0;

	puts("\nHello!\n");	
	printf("What number do you want to search for?: ");
	scanf("%d", &nr);
	while(getchar() != '\n');

	puts("In your list:");
	node *head = build_list();
	while (head != NULL) {
		node_nr++;
		printf("\tNode %d - %d\n", node_nr, head->data);
		head = head->next;
	}

	printf("\n\t%d appears %d times.\n\n", nr, count(nr));

	return 0;
}


node * build_list(void)
{
	node *fifth = (node *)malloc(sizeof (node));
	node *fourth = (node *)malloc(sizeof (node));
	node *third = (node *)malloc(sizeof (node));
	node *two = (node *)malloc(sizeof (node));
	node *first = (node *)malloc(sizeof (node));

	fifth->data = 11;		fifth->next = NULL;
	fourth->data = 44;		fourth->next = fifth;
	third->data = 33;		third->next = fourth;
	two->data = 22;			two->next = third;
	first->data = 11;		first->next = two;

	return first;
}


int count(int searched_number)
{
	node *head = build_list();
	int count = 0;

	while (head != NULL) {
		if (searched_number == head->data)
			count++;
		head = head->next;
	}

	return count;
}