/* LinkedListsBasics.pdf - Stanford */

/*
 * Build the list {1, 2, 3} in the heap and store
 * its head pointer in a local stack variable.
 * Returns the head pointer to the caller.
*/

void * BuildTwoThree(void);
{
	struct node {
		int 	data;
		struct node *next;
	};

	struct node *head;
	struct node *second;
	struct node *third;

/* Allocates 3 nodes in the heap */
	head = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));

/* Setup the first node */
	head->data = 1;
	head->next = second;		/* note: pointer assignment rule */

/* Setup the second node */
	head->data = 2;
	head->next = third;

/* Setup the third node */
	head->data = 3;
	head->next = NULL;

/* At his point, the linked list referenced by "head"
 * matches the list in the drawing.
 
	 |	  head		   	 second				  third
-----|------------------------------------------------
 data|	   1	    /-> 	2		  /->		3
*next|	second	  -/	  third		-/		   NULL
-----|------------------------------------------------

*/

 return head;
}
