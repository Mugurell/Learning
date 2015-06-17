/************************************************************************
* Exercise 1-19.
* Write a function reverse ( s} that reverses the character string s.		//! LOL, acu am vazut ca scrie "a function"
* Use it to write a program that reverses its input a line at a time.		// Ar fi o functie void ce printeaza la fel un
************************************************************************/	// for loop ce ia caracterele invers.......

#include <stdio.h>

int
main()
{
	int y, x = 0;
	char c;
	char prop[1000], invers[1000];
	do
	{
		for (;;)
		{
			c = getchar();      //getchar din bufferul lui stdin
								//eu intai scriu pe ecran ce vreau
								//si abia dupa ce dau enter mi le citeste
								//food for thought
			if (c == '~')
			{	printf("\nSo... Do you wanna stop?\n\t Okey..\n");
				printf("But first let me dazzle you a bit :-)\n");
				y=0;
				x--;		// scad 1 din x pt ca x++ mi-l incrementa dupa ce era folosit(v. randul 44)
				do
				{
					invers[y] = prop[x];
					/********************************************************************************
					* Test pt a vedea valorile variabilelor
					* printf("**Invers[%d] = prop[%d], adica %c = %c**\n", y, x, invers[y], prop[x]);
					*********************************************************************************/
					y++;
					x--;
				} while (x >= 0);
				invers[y] = '\0';
				putchar('\t');
				puts(invers);
				puts("\n\tMuahahaha!!! :-)");
				break;
			}
			else if (c != '\n')		//orice caracter in afara de \n
									//care ramane pentru else-ul de mai jos
			{
				prop[x++] = c;		// aici x-ul este incrementat dupa ce este folosit
			}
			else
			{
				y = 0;
				x--;			// scad 1 din x pt ca x++ mi-l incrementa dupa ce era folosit(v. randul 44)
				do
				{
					invers[y] = prop[x];
					y++;
					x++;
				} while (x >= 0);
				printf("X este %d", x);
				invers[y] = '\0';
				putchar('\t');
				puts(invers);
				//x = 0;   //pt ca altfel x-ul ramanea la-1 
						// don't really know why ...			//! v. randul 27/
			}
		}
	} while (c != '~');

	while (getchar() != '\n')
		continue;
	getchar();

	return 0;
}
