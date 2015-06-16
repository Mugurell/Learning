#include <stdio.h>

int main()
{
	
	/* keep values small with short */
	int a,b,u,s;

	a = 150;
	b = 300;
	u = a - b;
	s = a - b;
	
	printf("Unsigned variable  = %u\n" , u);   //%u in loc de %d ins direct unsigned integer ;-)
	printf("Signed variable = %d\n" , s);
	
	return(0);
		
}