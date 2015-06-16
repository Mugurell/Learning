#include <stdio.h>
#include <time.h>

int main(void)
{
	struct tm *t;			//o variabila pt struct tm
	time_t now;				//o variabila de tipul time_t
							//in care sa stochez timpul

	time(&now);				//get the epoch time
	t = localtime(&now);	//get the tm structure

	char *zile[] = {
		"Luni",
		"Marti",
		"Miercuri",
		"Joi",
		"Vineri",
		"Sambata",
		"Duminica"
	};

	char *luna[] = {
		"Ja",
		"Fe",
		"Ma"
	};

	printf("Astazi este %s %02d/%s/%02d.\n",
	       zile[t->tm_wday - 1],
	       t->tm_mday,
	       luna[t->tm_mon],
	       t->tm_year - 100);

	if (t->tm_hour > 12)
	{
		printf("Iar ceasul este %02d:%02d:%02d PM.\n",
		       t->tm_hour - 12,
		       t->tm_min,
		       t->tm_sec);
	}
	else
	{
		printf("Iar ceasul este %02d:%02d:%02d PM.\n",
		       t->tm_hour,
		       t->tm_min,
		       t->tm_sec);
	}


	getchar();
	return 0;

}