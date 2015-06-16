#include <stdio.h>
#include <time.h>

int main(void)
{
	struct tm *t;
	time_t now;

	now = time(NULL); 			//get the current epoch time
	t = localtime(&now);		//get the tm structure

	char *zile[] = {
		"Luni",
		"Marti",
		"Miercuri",
		"Joi",
		"Vineri",
		"Sambata",
		"Duminica"
	};

	char *luni[] = {
		"Ian",
		"Feb",
		"Martie",
		"Apr"
	};

	printf("Astazi este %s, %d %s %d.\n",
	       zile[t->tm_wday - 1],		//eu am incput cu Luni,
	       //tm_wday incepe cu Sunday
	       t->tm_mday,
	       luni[t->tm_mon],
	       t->tm_year + 1900);
	//asa e definit tm_year in struct_tm - year since 1900

	if (t->tm_hour > 12)
	{
		printf("Iar ceasul este %02d:%02d:%02d PM.\n",
		       //%02d are grija ca int-ul sa aiba 2 spatii
		       //iar daca e o singura cifra, aceasta sa aiba '0' inainte
		       t->tm_hour - 12,
		       t->tm_min,
		       t->tm_sec);
	}
	else
	{
		printf("Iar ceasul este %d:%02d:%02d AM.\n",
		       //%02d are grija ca int-ul sa aiba 2 spatii
		       //iar daca e o singura cifra, aceasta sa aiba '0' inainte
		       t->tm_hour,
		       t->tm_min,
		       t->tm_sec);
	}


	getchar();
	return 0;
}