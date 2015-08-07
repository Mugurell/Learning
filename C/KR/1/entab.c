/*********************************************************************************
* Exercise 1-21. 
*Write a program entab that replaces strings of blanks by the
* minimum number of tabs and blanks to achieve the same spacing.
* Use the same tab stops as for detab. - (1 tab are ocupa 5 spatii)
*When either a tab or a single blank would suffice to reach a tab stop,
* which should be given preference?  
* 	- R: ?? 
* Un tab ocupa 5 spatii, 1 space ocupa un singur spatiu!! Nu pot fi egale!?
**********************************************************************************/

/*
** Ce am inteles eu:
** Un program care imi citeste stdin
** si care inlocuieste sirurile de spatii scrise => trebuie sa scriu siruri de spatii !
** cu tab-uri sau spatii, cat mai putine, atunci cand le printez
*/



/******************************************************************************
* B U G  1:
* Daca dupa ce termin cu spatiile vine un sir de caractere (!= spatiu/tab)
* primul caracter este sarit, nu e printat.
* Noile caractere(!= spatiu/tab) sunt printate abia dupa ce primul e sarit
*
* FIXED
* La linia 76 am pus "if" in loc de "else if".
******************************************************************************/



#include <stdio.h>

#define IN 1        // if there's allready a space/tab immediatly before the char just read
#define OUT 0       // if the previous char was other than a space/tab

int main(void)
{
	char c;      		// variabila in care va fi stocat caracterul citit
	int x = 0;     		// variabila care imi numara fiecare spatiu (* 1 caracter) din stdin
	int y;      		// variabila de folosit in loopuri
	int t;      		// variabila ce va contine numarul de tab-uri necesare
	int s;      		// variabila ce va contine numarul de spatii necesare
	int space = OUT;    // flag pentru a semnaliza daca mai inainte a fost sau nu un spatiu/tab

	while ((c = getchar()) != '~') {

		/*Daca citesc spatiu, x e incrementat cu 1
		 * space va semnaliza ca am citit spatiu/tab*/
		if (c == ' ') {
			space = IN;
			++x;
		}
		/*Daca citesc tab, x e incrementat cu 5;
		 * space va semnaliza ca am citit spatiu/tab*/
		else if (c == '\t') {
			space = IN;
			x += 5;
		}
		/*Daca citesc orice alt caracter (inafara de spatiu sau tab)*/
		else {
			/*verific daca inainte am avut spatiu, caz in care execut algoritmul principal - obiectul programului*/
			if (space == IN) {
				t = x / 5;
				s = x % 5;
				//printf("***t=%d si s=%d***\n", t, s);
				if (t > 0)
					for (y = 0; y < t; y++)
						printf("*****");
				if (s > 0)
					for (y = 0; y < s; y++)
						printf("-");
				x=0;
				space = OUT;
			}
			/*daca inainte nu am avut spatiu/tab, printez caracterul citit
			 * si setez space sa arate ca am citit un alt caracter decat space/tab*/
			if(space == OUT){
				printf("%c", c);
				space = OUT;
				x=0;
			}
		}

	}
}
