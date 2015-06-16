/* The classic 3-Step Link In operation which adds 
** a single node to the front of a linked list
**
** 	1) Allocate
** Allocate the new node in the heap and set its .data to whatever 
** needs to be stored.
**		struct node* newNode;
**		newNode = malloc(sizeof(struct node));
**		newNode->data = data_client_wants_stored;
**
** 	2)Link Next
** Set the .next pointer of the new node to point to the current first 
** node of the list. This is actually just a pointer assignment.
** Remember: "assigning one pointer to another makes them point to the
** same thing."
**		newNode->next = head;
**
**	3)Link Head
** Change the head pointer to point to the new node, so it is now the 
** first node in the list.
** 		head = newNode;
*/

void LinkTest(void)
{
	struct node *head = BuildTwoThree;		// suppose this builds
											// the {2, 3} list
	struct node *newNode;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = 1;

	newNode->next = head;		// link next

	head = newNode;				// link head

/*
** So at first head(BuildTwoThree) pointed to the {2, 3} list,
** But now head points to the {1, 2, 3} list.

}