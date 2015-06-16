/* 
** Consider a CopyList() function that takes a list and returns a 
** complete copy of that list.
** One pointer can iterate over the original list in the usual way. 
** Two other pointers can keep track of the new list: one head pointer,
** and one tail pointer which always points to the last node in the new
** list. The first node is done as a special case, and then the tail
** pointer is used in the standard way for the others...
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int 	data;
	struct NODE *next;
} node;

node *CopyList(node *head);
void Push(node **head, int num);


int main(void)
{
	node *head = NULL;
	node *copy = NULL;
	int i;
	
	/*
	** First initialize the list using Push
	*/
	for (i = 0; i < 6; i++)
		Push(&head, i);

	/*
	** Print the original list
	*/
	puts("The original list:");
	i = 0;
	while (head != NULL) {
		i++;
		printf("\tNode %d - %d\n", i, head->data);
		head = head->next;
	}

	/*
	** Call the copy function and print the copy
	*/
	puts("\nThe copied list:");
	i = 0;
	copy = CopyList(head);
	while (copy != NULL) {
		i++;
		printf("\nNode %d - %i\n", i, copy->data);
		copy = copy->next;
	}
	
	return 0;
}


void Push(node **head, int num)
{
	node *current = (node *)malloc(sizeof(node));

	current->data = num;
	current->next = *head;
	*head = current;
}


node *CopyList(node *head)
{
	node *current = head;	// used to iterate over the original list
	node *newList = NULL;	// head of the new list;
	node *tail = NULL;		// kept pointing to the last node
							// in the new list

	while (current != NULL) {
		if (newList == NULL) {	// special case for the first node
			newList = (node *)malloc(sizeof(node));
			newList->data = current->data;
			newList->next = NULL;
			tail = newList;
		} else {
			tail->next = (node *)malloc(sizeof(node));
			tail = tail->next;
			tail->data = current->data;
			tail->next = NULL;
		}
		current = current->next;
	}	
	return newList;
}