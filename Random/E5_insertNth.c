#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int			data;
	struct NODE *next;
} node;

typedef enum {FALSE, TRUE} bool;

bool insertNth(node **head_ref, int index, int data);
node * build_list(void);
void clean(void);
void print_list(node *head);

int main(void)
{	
	int index, data;
	node *list_root = build_list();

	puts("\nYou have a nice linked list:");
	print_list(list_root);

	puts("\nLet's pretend you want to append a new node..");
	printf("\tAt what position would you want it?: ");
	scanf("%d", &index);
	clean();
	printf("\tAnd what data should it contain?: ");
	scanf("%d", &data);
	clean();

	if (insertNth(&list_root, index, data)) {
		puts("\nYour new list now is:");
		print_list(list_root);
		puts("\nGoodbye!\n");
	} else {
		puts("Error: Could not append a new node! :-(\n");
	}

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


void clean(void)
{
	while (getchar() != '\n')
		;
}


void print_list(node *head)
{
	int count = 0;

	if (head == NULL)
		puts("\nError: NULL header!\n");
	else {
	 	while (head != NULL) {
	 		count++;
	 		printf("\tNode %d - %d\n", count, head->data);
	 		head = head->next;
	 	}
	}
}


bool insertNth(node **head_ref, int index, int data)
{
	node *current = *head_ref;
	bool if_success = FALSE;

	node *new_list = (node *)malloc(sizeof(node));
	if (new_list == NULL) 
		if_success = FALSE;
	new_list->data = data;

	if (0 == index) {
		puts("\nAs you saw above, the starting position"
			" for this\n\t\t IS FUCKIN' 1 !!!"
			"\n\tJackass!\n");
		if_success = FALSE;
	} else if (1 == index) {
		puts("Sunt in cazul asta!");
		new_list->next = current;
		*head_ref = new_list;
		if_success = TRUE;
	} else {
		int list_nr = 0;
		node *previous = (node *)malloc(sizeof(node));
		if (previous == NULL)
			if_success = FALSE;

		while (current != NULL && list_nr < index-1) {
			list_nr++;
			previous = current;
			current = current->next;
		}
		previous->next = new_list;
		new_list->next = current;
		if_success = TRUE;
	}
	return if_success;
}
