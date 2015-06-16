#include <stdio.h>

#define SIZE 8

int main(void)
{
	char *names[] = {
		"Mickey",
		"Minnie",
		"Donald",
		"Daisy",
		"Goofy",
		"Chip",
		"Dale",
		"Pluto"
	};
	char *temp;
	int x, a, b;

	for(a=0; a<SIZE-1; a++)
		for(b=a+1; b<SIZE; b++)
		{
			x=0;
			while(*(*(names+a)+x))	//pana la '\0'
			{
				if(*(*(names+a)+x) > *(*(names+b)+x))
				{
					temp = *(names+a);		
					*(names+a) = *(names+b);
					*(names+b) = temp;
					break;
				}
				else if(*(*(names+a)+x) < *(*(names+b)+x))
					break;
				else		//in cazul in care caracterele sunt egale
					x++;	// sare la urmatorul caracter
			}
		}

	for(x=0; x<SIZE; x++)
		printf("\t%s\n", *(names+x));

	getchar();
	return 0;
}