/*
** Takes a list and a data value.
** Creates a new link with the given data and pushes it onto the front
** of the list.
** The list is not passed in by its head pointer.(a copy of its value)
** Instead the list is passed in as a "reference" pointer to the head 
** pointer -- this allows us to modify the caller's memory.
*/


void Push(struct node **headRef, int data)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));

	newNode->data = data;
	newNode->next = *headRef;	// The '*' dereferences back to the
								// real head
	*headRef = newNode;			// ditto
}


void Pushtest()
{
	struct node *head = BuildTwoThree;		// suppose this returns 
											// the list {2, 3}
	Push(&head, 1);		// note the '&'
	Push(&head, 13);

/* => head is now the list {13, 1, 2, 3}. */
}