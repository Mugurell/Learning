/*
** Complete the following declaration to initialize x so that the member
** a is three, b is the string hello, and c is zero. You may assume that
** x is stored in static memory. 

struct {
	int 	a;
	char 	b[10];
	float 	c;
} x = ..??

*/


#include <stdio.h>

/* Pentru ca struct e definita in static memory
** <=> va fi initializata cu valori default
*/

int main(void)
{
	printf("Am intrat!!\n");
typedef struct {
	int 	a;
	char 	b[10];
	float	c;		//va fi init cu 0,0000000 
	char 	d;		// va fi init cu "" 
	int 	e;		// va fi init cu 0 
}tag;
x =  {3, "Hello!"};

	puts("\nSo you've declared, in static!,");
	printf("\t%d,\n\t%s,\n\t%f,\n\t%c,\n\t%d\n\n",
		x.a, x.b, x.c, x.d, x.e);

tag y;
y.a = 3;
strcpy(y.b, "HEllo")



	return 0;
}