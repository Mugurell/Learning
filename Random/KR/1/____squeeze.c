/**********************************************************************
* Write an alternate version of squeeze ( s1, s2) that deletes
* each character in s 1 that matches any character in the string s2.
***********************************************************************/

#include <stdio.h>

int main(void)
{
	char c;
	char s1[1000];
	char s2[1000];
	int x = 0;          // variabila pt a incrementa pozitia din array-ul s1
	int y = 0;          // variabila pt a incrementa pozitia din array-ul s2
	int max;            // nr maxim de caractere in array (max (x,y))

	puts("You must say something on 2 rows");
	puts("Any letter that is repeated will be deleted :-S");
	puts("When you wanna stop, press '~'");
	puts("Start\n\n");

	while ((c = getchar()) != '~')
	{
		s1[x++] = c;
		if (c == '\n')
		{
tambalau:
			do
			{	c = getchar();
				s2[y++] = c;
			} while ((c != '\n') && (c != '~'));		//daca avem \n sau ~ conditia nu mai e implinita
			printf("Am iesit!!!!!!!");
			s1[x] = '\0';
			s2[y] = '\0';
			getchar();
			break;
		}
	}

	printf("**I made it**\n");

	getchar();

	max = (x > y) ? x - 1 : y - 1;      //-1 ca sa scadem null char
	printf("**max is %d**\n", max);
	printf("Y este %d\n\n", y);

	getchar();



	//===========================================================
	// MARE BUG
	// trebuie rescris tot algoritmul de mai jos
	// ==========================================================
	for (;;)
	{
		if (y == 0) {
			printf("You gotta say some more !\n");
			goto tambalau;
			break;
		}
		else {
			for (x = 0; x < max; x++)
				for (y = 0; y < max; y++) {
					if (s1[x] != s2[y]) {
						printf("%c", s1[x]);
						break;
					}
					else
						continue;
				}
		}
	}

	while (getchar() != '\n')
		continue;
	getchar();

	return 0;
}