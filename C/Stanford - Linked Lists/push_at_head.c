/*
** The easiest way to build up a list is by adding nodes at its 
** "head end" with Push(). 
** The code is short and it runs fast — lists naturally support
** operations at their head end. The disadvantage is that the elements
** will appear in the list in the reverse order that they are added.
** If you don't care about order, then the head end is the best.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct GIGI {
	int data;
	struct GIGI *next;
} gigi;

void Push(gigi **gogu, int data);

int main(void)
{
	int i;

	gigi *four = &(gigi) {44, NULL};
	gigi *three = &(gigi) {33, four};
	gigi *one = &(gigi) {22, three};
	//gigi *one = two;

	for (i = 0; i < 6; i++)
		Push(&one, i);

	i = 0;		// o sa numere cate noduri am.
	while(one != NULL)	{
		i++;
		printf("\tNodul %d - %d\n", i, one->data);
		one = one->next;
	}

	return 0;
}

void Push(gigi **gogu, int data)
{
	// 1) Aloci memorie.
	gigi *head = (gigi *)malloc(sizeof(gigi));

	// 2) Initializezi noul pointer.
	head->data = data;
	head->next = *gogu;
	
	// 3) Seteaza ca lista sa inceapa cu noul pointer.
	*gogu = head;
}