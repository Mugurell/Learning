#include <stdio.h>
#include <time.h>

int main(void)
{
	struct tm *tm;
	time_t now;
	int hour, minute;

	time(&now);
	tm = localtime(&now);

	hour = tm->tm_hour;
	minute = tm->tm_min;

	if (minute >= 30)
		hour += 1;

	hour %= 12;
	if (hour == 0)
		hour = 12;

	minute += 2;
	minute /= 5;
	if (minute == 0)
		minute = 12;

	printf("The big hand is at %d\n"
		   "\tand the small hand is at %d.\n\n",\
		   hour, minute);

	return 0;
}