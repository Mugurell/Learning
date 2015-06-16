/* Convert the following code fragment so that it uses a jump table 
** instead of a switch statement. 
 
	Node *list;
	Node *current;
	Transaction *transaction;
	typedef enum { NEW, DELETE, FORWARD, BACKWARD,
					SEARCH, EDIT } Trans_type;
	...
---------------------------------------------------------------------
	case NEW:
		add_new_trans( list, transaction );
		break;
	case DELETE:
		current = delete_trans( list, current );
		break;
	case FORWARD:
		current = current->next;
		break;
	case BACKWARD:
		current = current->prev;
		break;
	case SEARCH:
		current = search( list, transaction );
		break;
	case EDIT:
		edit( current, transaction );
		break;
	default:
		printf( "Illegal transaction type!\n" );
		break;
	}
---------------------------------------------------------------------*/

void add_new_trans(Node *list, Node **current, Transaction *transaction );
void delete_trans(Node *list, Node **current, Node *current );
void search (Node *list, Node **current, Node *Transaction);
void edit(Node *list, Node **current, Node *Transaction);

void forward(Node *list, Node **current, Node *Transaction)
{
	*current = (*current)->next;
}

void backward(Node *list, Node **current, Node *Transaction)
{
	*current = (*current)->prev;
}

void (*functions[]) = {add_new_trans, delete_trans, search, edit,
						forward, backward};

#define TRANS_NR (sizeof(functions) / sizeof(functions[1]))

/*
** Invoke the proper function to perform a transaction
** (this is where the switch statements should be)
*/
	if (transaction->type < 0 || transaction->type >= TRANS_NR)
		printf("Illegal transaction type\n");
	else
		functions[transaction->type](list, &current, transaction);