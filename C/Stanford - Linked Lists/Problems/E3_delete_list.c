/*
** Write a function DeleteList() that takes a list, deallocates all 
** of its memory and sets its head pointer to NULL (the empty list).
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct NODE {
	int 		data;
	struct NODE *next;
} node;

typedef enum {FALSE, TRUE} bool;
#define 	DELAY	1.5

node * build_list(void);
bool DeleteList(node *head);


int main(void)
{
	node *head = build_list();
	node *head_back = head;
	int count = 0;
	time_t then;

	puts("So you have a list:");
	while (head != NULL) {
		count++;
		printf("\tNode %d - %d\n", count, head->data);
		head = head->next;
	}
	head = head_back;

	printf("You're sure you wanna delete it?");
	printf("\n\t...\t... ? : ");
	time(&then);
	while (difftime(time(NULL), then) < DELAY)
		;
	char answer = toupper(getchar());

	switch (answer) {
		case 'Y':
			printf("\nOkey...\n\t....\t...\n\n");
			time(&then);
			while (difftime(time(NULL), then) < DELAY)
				;
			if (DeleteList(head))
				puts("Done!\n");
			else {
				puts("The list begged me for mervy .. and.. you know me");
				puts("Couldn't do it.\nThe list is still alive & kicking!\n");
			}
			break;
		case 'N':
			puts("You have a big heart!\n");
			break;
		default:
			puts("I know man, hard to press [Y] or [N] :-|\n");
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

	fifth->data = 11;		fifth->next = NULL;
	fourth->data = 44;		fourth->next = fifth;
	third->data = 33;		third->next = fourth;
	two->data = 22;			two->next = third;
	first->data = 11;		first->next = two;

	return first;
}


bool DeleteList(node *head)
{
	node *next;
	node *current = head;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	head = NULL;

	return TRUE;
}