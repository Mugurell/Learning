#include <stdio.h>
#include <stdlib.h>

typedef struct GOGU {
	int 	data;
	struct GOGU *next;
} gigi;

void Push(gigi **gogu, int data);
gigi *AppendNode(gigi **headRef, int data);

int main(void)
{
	gigi *head = NULL;
	int i;

	for (i = 0; i < 6; i++)
		AppendNode(&head, i);

	i = 0;		// o sa numere cate noduri am
	while (i < 5) {
		i++;
		printf("\tNode %d - %d\n", i, head->data);
		head = head->next;
	}

	return 0;
}


gigi *AppendNode(gigi **headRef, int data)
{
	gigi *current = *headRef;
	puts("Inainte de special case");
	// special case for empty list.
	if (current == NULL)
		Push(headRef, data);
	else {
		// locate the last node.
		while (current->next != NULL)
			current = current->next;
	}
	puts("Dupa special case");
	// Build the node after the last node.
	Push(&(current->next), data);
	puts("A terminnat si pushul"); 
}


void Push(gigi **gogu, int data)
{
	gigi *head = (gigi *)malloc(sizeof(gigi));

	head->data = data;
	head->next = *gogu;
	*gogu = head;
}