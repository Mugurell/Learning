/*
 Consider the problem of building up the list {1, 2, 3, 4, 5} by appending the nodes to the
tail end. The difficulty is that the very first node must be added at the head pointer, but all
the other nodes are inserted after the last node using a tail pointer. The simplest way to
deal with both cases is to just have two separate cases in the code. Special case code first
adds the head node {1}. Then there is a separate loop that uses a tail pointer to add all the
other nodes. The tail pointer is kept pointing at the last node, and each new node is added
at tail->next. The only "problem" with this solution is that writing separate special
case code for the first node is a little unsatisfying. Nonetheless, this approach is a solid
one for production code — it is simple and runs fast.
*/

/************************B U G*****************************/
/***** Segmentation fault din cauza la special case...*****/


#include <stdio.h>
#include <stdlib.h>

typedef struct GOGU {
	int 	data;
	struct GOGU *next;
} gigi;

gigi *Append(gigi **goguRef, int data);

int main(void)
{
	puts("Am inceput main");
	gigi *head = NULL;
	int i;

	for (i = 0; i < 6; i++)
		Append(&head, i);

	i = 0;		// o sa numere cate noduri am
	while (i < 5) {
		i++;
		printf("\tNode %d - %d\n", i, head->data);
		head = head->next;
	}

	return 0;
}

gigi *Append(gigi **goguRef, int data)
{
	puts("Am intrat in fucntie**");
	gigi *current = *goguRef;
	puts("Am alocat current = goguref");
	printf("*current este %p\n", current);
	gigi *newNode = (gigi *)malloc(sizeof(gigi));
	newNode->data = data;
	newNode->next = NULL;

	puts("Inainte de special case");
	// special case for lenght 0
	if (current == NULL)
		*goguRef = newNode;

	else {
		// Locate the last node
		puts("Dupa special case, in else");
		while(current->next != NULL)
			current = current->next;
	}
	current->next = newNode;
	puts("Am terminat prima data");
}

