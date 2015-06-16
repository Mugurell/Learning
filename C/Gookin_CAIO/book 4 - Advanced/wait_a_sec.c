#include <stdio.h>
#include <time.h>

#define DELAY 0.1

void pause (void)
{
	time_t then;

	time(&then);


/******double difftime (time_t end, time_t beginning);******
* Calculates the difference in seconds 
* between beginning and end.
************************************************************/
	while(difftime(time(NULL), then) < DELAY)
		;
}


int main(void)
{
	int x;

	for(x=10; x>0; x--)
	{
		printf("%d\n", x);
		pause();
	}
	printf("\nBlast Off!");

	getchar();
	return 0;

}
