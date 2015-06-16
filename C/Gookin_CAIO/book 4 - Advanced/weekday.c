#include <stdio.h>
#include <time.h>

int main(void)
{
	char *wdays[] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
	};
	//incepem cu sunday pt ca asa e in struct tm{tm_wday}
	//altfel puteam sau incep cu monday si sa pun +1 in printf

	struct tm *t;			//struct_tm e definita in time.h
	time_t now;

	time(&now);			   //get the current time
	t = localtime(&now);   //get the tm structure

	printf("Today is %s.\n", wdays[t->tm_wday]);

	getchar();
	return 0;
}