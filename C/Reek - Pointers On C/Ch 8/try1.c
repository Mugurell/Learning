#include <stdio.h>

#define SIZE 50
int x[SIZE];
int y[SIZE];
int i;
int *p1, *p2;

void try1(void);
void try2(void);
void try3(void);
void try4(void);
void try5(void);

int main(void)
{
	try1();

	return 0;
}

void try1()
{
	for( i = 0; i < SIZE; i++)
		x[i] = y[i];
}