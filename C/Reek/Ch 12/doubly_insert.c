/*
** Insert a value into a doubly linked list. 
** rootp is a pointer to the root node, and value is the new value 
** to be inserted.
** Returns:  0 if the value is already in the list, 
** 			-1 if there was no memory to create a new node, 
**			 1 if the value was added successfully.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *fwd;
	struct Node *bwd;
	int 		value;
} node;

int dll_insert(node *rootp, int value);

int main(void)
{


	return 0;
}

int dll_insert(node *rootp, int value)
{
	node *this, *next, *new_node;

	/*
	** See if the value is allready in the list. Return it if it is.
	** Otherwise, allocate a new node for the value.
	** "new_node" will point to it.
	** "this" will point to the node that the new value should follow,
	** "next" will point to the one after it.
	*/
	for (this = rootp; (next = this->next) != NULL; this = next) {
		if (next->value == value)
			return 0;
		if (next->value > value)
			break;
	}

	new_node = (node *)malloc(sizeof(node));
	if (new_node == NULL)
		return -1;
	new_node->value = value;

	/*
	** Add the new node to the list
	*/
	if (next != NULL) {
		/*
		** Case 1 or 2: not at the end of the list.
		*/
		if (this != rootp) {	/* Case 1: not at front */
			new_node->fwd = next;
			this->fwd = new_node;
			new_node->bwd = this;
			next->bwd = new_node;
		} else {				/* Case 2: at front */

		}
	}
}
