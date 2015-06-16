#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE *next;
} node;

void change_head(node **head_ref);

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
	third = &(node) {36, NULL};
	node *second = &(node) {24, third}; 
	node *first = &(node) {12, second};

	puts("So, originally, your lists say:");
	node *current = first;
	int i = 0;
	while (current != NULL) {
		i++;
		printf("\tNode %d - %d\n", i, current->data);
		current = current->next;
	}

	puts("\nBut after some twickling.. it says..");
	change_head(&first);
	current = first;
	i = 0;
	while (current != NULL) {
		i++;
		printf("\tNode %d - %d\n", i, current->data);
		current = current->next;
	}

	return 0;
}

void change_head(node **head_ref)
{
	/*
	** Argumentul node **head ref:
	** avem un pointer de pentru structura node: *head_ref
	** si mai avem un pointer care contine &first.
	** Astfel ca mai jos, prin *head_ref accesam defapt 
	** valoarea lui first, care a fost passed by reference.
	** Hence, putem sa il modificam.
	*/
	
	//node *new_head;// = (node*)malloc(sizeof(node));
	node *new_head; = (node*)malloc(sizeof(node));

	//new_head = &(node) {4738920, *head_ref};
	new_head->data = 2345;	// daca fac asa, cu new_head pe stack
							// -> segmentation fault
	new_head->next = *head_ref;
	*head_ref = new_head;
}

