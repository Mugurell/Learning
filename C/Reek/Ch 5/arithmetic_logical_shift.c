#include <stdio.h>

int main(void)
{
	signed int nr = -12;

	nr >>=1;

	/*If the printed result is negative -> arithmetic shift was used
	  Otherwise, logivsl shift was used*/
	
	printf("Nr e acum %d", nr);

	return 0;
}