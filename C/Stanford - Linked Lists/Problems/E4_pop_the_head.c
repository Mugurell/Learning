/* 
** Extract the data from the head node, delete the node, advance the 
** head pointer to point at the next node in line. 
** Uses a reference parameter since it changes the head pointer.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define 	DELAY	1.3

typedef struct NODE {
	int 		data;
	struct NODE *next;
} node;

typedef enum {FALSE, TRUE} bool;


node * build_list(void);
bool pop(node **head_ref);
void print_list(node *head);
void clean();


int main(void)
{
	int answer;
	time_t then;
	node *root;

	puts("\nLet's say you have a linked list:");
	print_list(build_list());

	puts("\nIt's pretty nice...");
	puts("\nBut how about chopping it's head off?");
	printf("Agree? [Y] / [N] : ");
	answer = getchar();
	clean();
	if (answer > 'a' && answer < 'z')
		answer += 'A' - 'a';
	switch (answer) {
		case 'Y':
			root = build_list();
			puts("\nYou sadistic head chopper you!");
			if (pop(&root)) {
				time(&then);
				while (difftime(time(NULL), then) < DELAY)
					;
				printf("\t...\t...\n");
				puts("Done\n");
			}
			break;
		case 'N':
			puts("\n\tYou have a big heart!");
			puts("Doesn't do nothing for you, but.. it's .. cool!?\n");
			return 0;
		default:
			puts("I understand man, hard to press [Y] bor [N]\n");
			return 0;
	}

	puts("\nDo you want to see the remainders?");
	printf("Are you this cruel? [Y] / [N] : ");
	answer = getchar();
	clean();
	if (answer > 'a' && answer < 'z')
		answer += 'A' - 'a';
	switch (answer) {
		case 'Y':
			puts("\nOkey.. \nReady?..");
			time(&then);
			while (difftime(time(NULL), then) < DELAY)
				;
			printf("\t...\t...\n\n");
			print_list(root);
			time(&then);
			while (difftime(time(NULL), then) < DELAY)
				;
			puts("\nBye!\nYou degenerate you!\n");
			break;
		case 'N':
			puts("\nThere is still hope for you!\n");
			break;
		default:
			puts("Too terrified to press [Y] or [N]?");
			puts("I understand.");
			puts("Leave, I'll deal with this mess myself.\n");
	}
	return 0;
}

bool pop(node **head_ref) 
{
	node *first = *head_ref;
	
	*head_ref = first->next;
	free(first);

	return TRUE;
}

void print_list(node *head)
{
	int count = 0;

	while (head != NULL) {
		count++;
		printf("\tNode %d - %d\n", count, head->data);
		head = head->next;
    }
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
	while(getchar() != '\n')
		;
}