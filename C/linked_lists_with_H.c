#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

#define 	TRUE	1
#define 	FALSE	0

typedef struct NODE{
	char nume[100];
	int age;
	struct NODE *next;
} node;

node *head = NULL;
node *tail = NULL;

int count = 0; 		//va tine minte cate noduri avem in lista

bool insert_node(int new_pos);	// new_pos e pozitia unde vreau sa inserez ceva
void remove_node (int new_pos); 	// -||- sterg un node
void print_list(void);
void clean(void)
{
	while (getchar() != '\n')
		continue;
}

int main(void)
{
	char ch;
	int pozitie;

	do {
		puts("\nChoose your whatever:");
		printf("I - Insert\nR - Remove\nP - Print\nQ - Quit\n");
		printf("Your choice > ");
		ch = toupper(getchar());
		clean();
		switch (ch) {
			case 'I':
				printf("Where do you want to insert something? ");
				scanf("%d", &pozitie);
				clean();
				printf("Ok, let's insert something into %d\n", pozitie);
				insert_node(pozitie);
				break;
			case 'R':
				printf("What position do you want removed: ");
				scanf("%d", &pozitie);
				clean();
				printf("Ok, let's remove the node from %d\n", pozitie);
				remove_node(pozitie);
				break;
			case 'P':
				print_list();
				break;
			case 'Q':
				puts("Goodbye then!");
				break;
			default:
				puts("Wrong choice!");
				break;
		}
	} while (ch != 'Q' );

	return 0;
}

bool insert_node(int new_pos)
{
	node *new = (node *)malloc(sizeof(node));
	assert(new != NULL);

	printf("Enter your name: ");
	fgets(new->nume, 100, stdin);
	printf("Enter your age: ");
	scanf("%d", &new->age);
	new->next = NULL;

	clean();

	if (new_pos > count) {
		puts("Your chosen position is too big.");
		puts("Sometimes too big, is too big!");
		puts("We will insert at the tail.");

		if (tail == NULL) 
			head = tail = new;
		else {
			// puts("Pula 1!!!!");
			// tail = tail->next;
			// puts("Pula 2 !!!!!!");
			tail->next = new;
			 tail = new;
		}

	} else {
		if (head == NULL && tail == NULL) {
			puts("Sunt in if!!!!!!");
			head = tail = new;
		} else if (new_pos == 0) {
			new->next = head;
			head = new;
		} else {
			node *temp = head;
			int i = 0;
			// do {
			// 	i++;
			// 	temp = temp->next;
			// } while (i < new_pos);

			for(i = 0; i < new_pos-2; i++)
				temp = temp->next;
			
		/*
		** next-ul lui next sa pointeze catre next-ul lui temp
		** temp fiind cea mai mare pozitie de dinainte de count
		** Apoi next-ul lui temp sa pointeze cagtre noul nod.
		** -> temp-> new
		**			new->next->temp->next, care e defapt nodul 
		** catre care pointa temp anterior samd. */
			new->next = temp->next;
			temp->next = new;
		}
	}

	count++;
	return FALSE;
}

void remove_node (int new_pos) 
{
	if (0 == count) {
		puts("Za list is empty bha!");
		return;
	} else if (new_pos > count) {
		printf("Za list has only %d nodes!\n", count);
		return;
	} else if (0 == new_pos) {
		node *temp = head;
		head = head->next;
		free(temp);
	} else {
		node *temp = head;
		int i = 0;

		for (; i < new_pos-2; i++, temp = temp->next)
			;
		node *delete = temp->next;
		temp->next = delete->next;
		free(delete);
	}

	count--;
}

void print_list(void)
{
	printf("Your list has %d nodes.\n", count);
	node *temp = head;
	if (temp == NULL)
		puts("Za list is empty bha!");
	else {
		int i = 0;
		while (temp != NULL) {
			i++;
			printf("Node %d:\n", i);
			printf("\tName: %s\tAge: %d.\n", temp->nume, temp->age);
			temp = temp->next;
		}
	}
}


*(*(*array))+1 array[0][0][1]