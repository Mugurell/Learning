#include <stdio.h>

int x = 1;			// asta are scop global
					// toate varabilele dinainte de main se numesc variabile globale!!!

void pula(int);		// de obicei intai se declara functiile, apoi variabilele
void pula_2(void);

int main(void)
{

	int x = 2;

	x++;

	printf("%d\n", x);
	pula(23);
	pula_2();
	getchar();

	return 0;
}



void pula(int a)
{ 
	int x = 13;			//variabila x cu scop local
						//daca am o alta variabila locala cu acelasi nume ca o variabila globala
						//	ea va fi mascata

	printf("%d\n", x);
}



void pula_2(void)
{
printf("%d", x);
}