/*
** In this fine I will define a structure along with pointer variables
** to be used as nodes in other programs that deal with linked lists.
*/

// typedef struct NODE {
// 	int				data;
// 	struct NODE 	*next;
// } node;

// node *fifth 	= &(node) {55, NULL};
// node *fourth 	= &(node) {44, fifth};
// node *third 	= &(node) {33, fourth};
// node *two		= &(node) {22, third};
// node *head		= &(node) {11, two};


/************** This doesn't work. *********************
*******	Why? *******************************************
**
** Because I try to assign a value that isn't knowable
** by the compiler at the compile time, but rather it
** will be known at runtime time. 
** Hence the:
**		error: initializer element is not constant;
** 		error: (near initialization for ‘fourth’);
**
*******************************************************/



