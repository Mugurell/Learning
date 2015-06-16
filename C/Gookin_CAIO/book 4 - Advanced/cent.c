#include <stdio.h>

int main(void)
{
	int cent[8];
	int x, *p2c;

	p2c = cent;

	for(x=0; x<8; x++)
	{
		*(p2c+x) = (x+1) * 100;
		printf("cent[%d] = %d\n", x, *p2c+x);

/******************** sau *********************
		*p2c = (x+1) * 100;
		printf("cent[%d] = %d\n", x, *p2c++);
**********************************************/



/**************** sau**************************
		*p2c = (x+1) * 100;
		printf("cent[%d] = %d\n", x, p2c[0]);
	//	asta merge pt ca declaratia de mai sus
	//scrie doar la primul elem din array
***********************************************/



/******************* sau ***************************
		*p2c = (x+1) * 100;
		printf("cent[%d] = %d\n", x, *p2c++);
	// asta creste locatia din array in printf
	// printeaza ce se afla la locatia respectiva
****************************************************/

	}

	getchar();

	return 0;
}