/* 
** Write a program to create the data structure in the following
** diagram. The last three objects are structures which are 
** dynamically allocated. The first object, which may be static,
** is a pointer to a structure. You do not need to make this 
** program general as we will discuss this data structure in 
** the next chapter. 
**
**
**   head     /->	 5		 /->	10 	   /->	15 
**    ..	-/	    ..	   -/		..	 -/	 	 0 
**
*/


/*
** Create a particular linked list of dinamically
** allocated nodes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct NODE {
	int value;
	struct NODE *link;
} Node;

Node * newnode(int value)
{
	Node *new;

	new = (Node *)malloc(sizeof(Node));
	assert(new != 0);
	new->value = value;
	return new;
}

int main(void)
{
	Node *head;

	head = newnode(5);
	head->link = newnode(10);
	head->link->link = newnode(15);
	head->link->link->link = 0;		/* 0 == NULL */
}