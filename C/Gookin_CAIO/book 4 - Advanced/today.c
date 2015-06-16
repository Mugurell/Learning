#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t now;

	//time(&now);
	now = time(NULL);		//both do the same


/*This is the epoch time - seconds passed from 1 jan 1970*/
	printf("It is now %d.\n", now);


/*This is the current time*/
	printf("It is really %s.\n", ctime(&now));

	getchar();
	return 0;
}