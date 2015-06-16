#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE, TRUE} bool;

typedef struct NODE {
	int		data;
	struct NODE *next;
} node;

int count = 0;

bool add2tail(node **head_ref, int new_nr);
void print_list(node *head);
void clean(void);

int main(void)
{

/************************ PLM ****************************
** Acu vad ca nu am folosit tail pointer...
** Daca vroiam, puteam sa folosesc 
**		while (head != NULL) {
**			tail = head;
**			head = head->next; }
***********************************************************/

	node *three = &(node) {33, NULL};	count += 1;
	node *two 	= &(node) {22, three};	count += 1;
	node *head 	= &(node) {11, two};	count += 1;
	int new_nr;

	printf("So at first your structure has %d nodes:\n", count);
	print_list(head);

	puts("\nSay you want to enter a new node, with a higher number..,");
	printf("\tSay...?: ");
	scanf("%d", &new_nr);
	clean();

	if (add2tail(&head, new_nr)) {
		puts("\nCool!");
		printf("So now your list has %d nodes:\n", count);
		print_list(head);
	}

	return 0;
}


void clean(void)
{
	while (getchar() != '\n')
		;
}


void print_list(node *head)
{
	int x = 0;

	while (head != NULL) {
		x++;
		printf("\tNode %d - %d\n", x, head->data);
		head = head->next;
	}
}


bool add2tail(node **head_ref, int new_nr)
{
	node *current = *head_ref;
	bool result;
	node *new_node = (node *)malloc(sizeof(node));


	while (current->next != NULL) {
		current = current->next;
	}

	if (current->data > new_nr) {
		puts("\n\tI asked for a new bigger number!");
		puts("\tIs that so hard?");
		puts("\t\tPffff");
		result = FALSE;
	} else {
		/****************************************************
		******* new_node = &(node) {new_nr, NULL}; *********
		****************************************************
		** Daca folosesc asa , dupa ce ies din functia asta 
		** new_node isi pierde valorile, chiar daca il declar static
		** Solutia gasita e mai jos **/
		new_node->data = new_nr;
		new_node->next = NULL;
		current->next = new_node;
		count++;
		result = TRUE;
	}

	return result;
}