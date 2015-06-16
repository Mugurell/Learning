#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int 		data;
	struct NODE *next;
} node;

void push(node **head_ref, int num);  // - BUGGED. 
/* Nush dc plm nu salveaza elementele de dinainte.. */
/************ Not bugged anymore ! ******************/

int main(void)
{
	int i = 0;
	node *second = &(node) {22, NULL};
	node *first = &(node) {11, second};
	node *first_backup = first;

	puts("So at first your list had..:");
	while (first != NULL) {
		i++;
		printf("\tNode %d - %d\n", i, first->data);
		first = first->next;
	}
/****************** L O L *****************************
** am descoperit bugul !!!!!!!!!!!!
** first = first->next.  Adica... NULL !!!!
** deci mai jos trimiteam NULL
** de asta nu mai aveam alte elemente in coada..
** Solutia: resetez first.
******************************************************/

	first = first_backup;
	puts("\nBut after some twickling.. it now says..");
	for (i = 0; i<100; i+=21)
		push(&first, i); 
	i = 0;
	while(first != NULL) {
		i++;
		printf("\tNode %d - %d\n", i, first->data);
		first = first->next;
	}

	return 0;
}

void push (node **head_ref, int num)
{
	node *new_head = (node *)malloc(sizeof(node));
	/* Daca nu il aloc dinamic, ci pe stac
	** funny things happen.... */

	new_head->data = num;
	new_head->next = *head_ref;
	*head_ref = new_head;

}