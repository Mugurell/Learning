#include <stdio.h>

int main()
{
	int a, b;

	printf("\tHere's your twos table\n\n");
/*     a=1; 
         for(b=2;b<=20;b=b+2) 
	{
		  printf(“2 * %d = %d\n”,a,b);
		   a=a+1;
     }
*/
	for (a = 1, b = 2; b < 20; ++a, b+=2)
	{
		printf("\t2*%d=%2d\n", a, b);
	}
	return (0);
}