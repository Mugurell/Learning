#include <stdio.h>

#define SIZE 5

int * odds(void);

int main(void)
{
	int x, *n;

	n = odds();

	for(x=0; x<SIZE; x++)
		printf("Element #%d = %d\n", x, *(n+x));

	getchar();
	return 0;
}

int * odds(void)
{
	int x; 
	static int o[SIZE];
/********** static because ********************************
*Functions discard their variable’s values 
* when the function is done. 
*To retain the values, you must make the variable static.
**********************************************************/

	for(x=0; x<SIZE; x++)
		o[x] = 2*x+1;

	return o;
}