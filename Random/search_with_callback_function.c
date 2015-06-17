#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct Node {
	int 	data;
	char 	name[10];
	struct Node *next;
} node;

typedef enum {FALSE, TRUE} bool;

node * build_list(void);
bool compare_int(void const *, void const *);
bool compare_string(void const *, void const *);
void print_list(node *root);
node *search_list(node *root, void const *value, bool (*ptr2cmp)(void const *list_value, void const *searched_value));
char ask_what2search(char *ptr2name, int *ptr2val);
void free_dinamic_pointers(node *root);
bool find_value(char value_type, node *root, char *ptr2name, int *ptr2val);


int main(void) 
{
	node *list_head = build_list();
	char response, searched_name[10], *ptr2name = searched_name;
	int searched_value, *ptr2val = &searched_value;

	puts("\nLet's start with a nice linked list:");
	print_list(list_head);

	/*
	** Ask what to search for (name or digit).
	** If the response it's valid, search for it.
	*/
	puts("\nLet's say you wanna search for something in the list..");
	response = ask_what2search(ptr2name, ptr2val);

	/* 
	** If the searched value was found, print it's location.
	** Else, finish the program.
	*/
	if (find_value(response, list_head, ptr2name, ptr2val))
		;
	else
		puts("\tGoodbye!\n");

	free_dinamic_pointers(list_head);

	return 0;
}


node *search_list(node *root, void const *value, bool (*ptr2cmp)(void const *list_value, void const *searched_value))
{
	node *current = root;

	while (current != NULL) {
		if (ptr2cmp(&current->name, value) == TRUE)
			break;
		else if (ptr2cmp(&current->data, value) == TRUE)
			break;
		current = current->next;
	}
	return current;
}


bool find_value(char value_type, node *root, char *ptr2name, int *ptr2val)
{	
	bool found;
	node *list_containg_value = NULL;

	if (value_type == 'N') {
		list_containg_value = search_list(root, ptr2name, &compare_string);
		if (list_containg_value == NULL) {
			found = FALSE;
			printf("\nSorry, coudn't find \"%s\" in the list.\n\n", ptr2name);
		} else {
			found = TRUE;
			printf("The value \"%s\" was found at %p.\n\n", ptr2name, (void*)list_containg_value);
		}
	} else if (value_type == 'D') {
		list_containg_value = search_list(root, ptr2val, &compare_int);
		if (list_containg_value == NULL) {
			found = FALSE;
			printf("\nSorry, coudn't find \"%d\" in the list.\n\n", *ptr2val);
		} else {
			found = TRUE;
			printf("\tThe value \"%d\" was found at %p.\n\n", 
				*ptr2val, (void*)list_containg_value);
		}
	} else
		found = FALSE;

	return found;
}


char ask_what2search(char *ptr2name, int *ptr2val)
{
	char choice;
	char name[10];
	int value;

	printf("\nShould it be a name or a digit? [N] / [D]\n\t\t\t-> ");
	choice = getchar();
	while (getchar() != '\n')
		continue;

	if (choice > 'a' && choice < 'z')
		choice += 'A' - 'a';

	switch (choice) {
		case 'N':
			printf("What name would you want to search?\n\t\t\t-> ");
			fgets(name, 10, stdin);
			name[strcspn(name, "\n")] = 0;
			strcpy(ptr2name, name);
			/* the name value is on stack;
			** it will be discarded after exit function 
					ptr2name = name;	- should not be used
			*/
			break;
		case 'D':
			printf("What value would you search for?:\n\t\t\t-> ");
			scanf("%d", &value);
			while (getchar() != '\n')
				continue;
			*ptr2val = value;
			break;
		default:
			printf("And \"%c\" stands for a name or a digit ?!\n", choice);
			puts("\t\t:-|");
			puts("But I understand you man...");
			puts("It's not your fault, it's your parents!\n");
			break;
	}

	return choice;
}


bool compare_int(void const *list_value, void const *searched_value)
{
	if (*(int *)list_value == *(int *)searched_value)
		return TRUE;
	else 
		return FALSE;
}


bool compare_string(void const *list_value, void const *searched_value)
{
	if (0 == strcasecmp((char *)list_value, (char *)searched_value))
		return TRUE;
	else 
		return FALSE;
}


node * build_list(void)
{
	node *fifth = (node *)malloc(sizeof (node));
	node *fourth = (node *)malloc(sizeof (node));
	node *third = (node *)malloc(sizeof (node));
	node *two = (node *)malloc(sizeof (node));
	node *first = (node *)malloc(sizeof (node));

	fifth->data = 55;		fifth->next = NULL;
	fourth->data = 44;		fourth->next = fifth;
	third->data = 33;		third->next = fourth;
	two->data = 22;			two->next = third;
	first->data = 11;		first->next = two;
	
	strcpy(fifth->name, "Ana");
	strcpy(fourth->name, "Bogdan");
	strcpy(third->name, "Cristi");
	strcpy(two->name, "Didina");
	strcpy(first->name, "Elena");

	return first;
}


void print_list(node *head)
{
	int count = 0;

	while (head != NULL) {
		count++;
		printf("\tNode %d: (%p) - %6s - %d\n", 
			count, (void *)head, head->name, head->data);
		head = head->next;
	}
}


void free_dinamic_pointers(node *root)
{
	while (root != NULL) {
		node *temp = root;
		root = root->next;
		free(temp);
	}
}
