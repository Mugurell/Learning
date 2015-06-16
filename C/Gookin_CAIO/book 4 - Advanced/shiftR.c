/****************************************************
* The official format for bit shifting to the right:
* result = value >> steps;
****************************************************/


#include <stdio.h>

int main(void)
{
	int v,r;

	printf("Enter an integer value %c ", 16);
	scanf("%d", &v);

	r = v >> 1;			//shift bits one notch ro the right
// 	v >>=1  - the bits from v are shifted on notch to the right,
// 				 then that value is	saved in v again;

	printf("%d cut in half is %d\n\n", v, r);

	printf("Now enter a number to be quartered %c", 26);
	scanf("%d", &v);
	v >>= 2;
	printf("\tAnd the result would be.. %d", v);

	while(getchar() != '\n')
		continue;
	getchar();

	return 0;
}