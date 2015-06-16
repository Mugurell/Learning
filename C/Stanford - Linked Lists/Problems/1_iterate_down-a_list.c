#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE *next;
} node;

int lenght(node *head);

int main(void)
{
	/*
	** First make sure you have a linked list with some nodes.
	*/

	// node *first = (node*)malloc(sizeof(node));
	// node *second = (node*)malloc(sizeof(node));
	// node *third = (node*)malloc(sizeof(node));

	/* 
	******* Compound literal as per C99 ********
	** Don't need to be allocated in heap, since they are
	** auto variables <-> they are stored on stack.
	** Note the inverse order bc the second argument
	** which requires that it should allready be declared.
	*/
	node *third;
	third = &(node) {3, NULL};
	node *second = &(node) {2, third}; 
	node *first = &(node) {1, second};

	puts("After various complex calculations I would say...");
	printf("You have a linked list with %d nodes.\n\n",lenght(first));

	return 0;
}

int lenght(node *head)
{
	// node *current = head;
	// int i = 0;

	// while(current != NULL) {
	// 	i++;
	// 	current = current->next;
	// }

	/*
	** Could be also writeen as a for loop
	*/
	node *current;
	int i = 0;
	for(current = head; current != NULL; i++, current = current->next)
		;

	return i;
}