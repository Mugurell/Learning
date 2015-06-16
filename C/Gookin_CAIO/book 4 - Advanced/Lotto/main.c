#include "lotto.h"
#include <stdio.h>		//necesar pt getchar

int ball[BALLS]; 		/*Global lotto ball array*/

int main(void)
{
	init();
	select();
	sort();
	display();

	getchar();
	return 0;
}