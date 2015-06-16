/*
** Given a linked list head pointer, compute
** and return the number of nodes in the list.
*/


int Lenght(struct node *head)
{
	struct node *current;
	int count = 0;

	current = head;		// sharing the same pointee

	while(current != NULL) {
		count++;
		current = current->next;
	}

	return count;
}