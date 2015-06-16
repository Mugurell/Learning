#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/************************************************************
* MODURI	DE	A	DEREFERENTIA	POINTERI
* IN	CAZUL	ARRAY-URILOR
* -----------------------------------------------------------
  pointer [3]
  *(pointer+3) 	sunt exact acelasi lucru(dereferentiere in ambele cazuri)

  printf("%s", pointer)
  printeaza tot stringul catre care pointeaza pointer
  (Nu mai e nevoie de *
  Asta e exceptie:
  DACA VREI SA PRINTEZI TOT STRINGUL II DAI POINTERUL
  DACA VREI SA PRINTEZI UN ELEMENT DEREFERENTIEZI (vezi mai sus)

  ************************************************************/




char *invers(char *sentence, int nr);
char *invers2(char *sentence, int nr);   /* has a mistake see below why(way below)*/

int main()
{
	char prop[100] = {'\0'};
	int x =0;
	char *sentence = prop;

	printf("prop initializata cu null character says _%s_\n", sentence);
	printf("Say something %c\n\t", 31 );
	fgets(prop, 100, stdin);
	x = strlen(prop) - 1;
	prop[x] = '\0';

	printf("prop orig - _%s_, si lungimea originala este %d\n", sentence, x);

//! sentence SI prop SUNT ACELASI LUCRU !!!
//! FIINDCA SENTENCE POINTEAZA CATRE PRIMUL ELEMENT AL LUI PROP

 	char *result = invers(prop, x);
	printf("prop invers este %s", result);

	/**&%!#$@%#^$&%*^&(*&^%$@#%^$&*(&*^%$#^%^&^*(&%$#@@
	* super important&critical best practice(according to Horia)
	* dupa ce termini cu un pointer alocat dinamic (malloc/calloc)
	* TREBUIE	DEALOCAT (sau mai simplu spus , bagi free)
	&^&$@#@%^%^&*&(&(%$^*(*&((&%$^*(*)*&&%^$*&()^&%^^&**&&%$*/


	free(result);
	/* result pointeaza catre blocul de memorie alocat dinamic in functia invers
	* *result = invers(prop, x) = prop_inv
	* iar lui prop_inv i-am dat malloc in functia invers
	*/


/* gata cu testele
	printf("*Sentence says: %s",  sentence);
	printf("*sentence says %c\n", sentence[1]);
	printf("*sentence says %c\n", prop[2]);
	printf("*sentence says %c\n", *(prop+2));


	//**************************(&*(^&&*^&*^&*(^*(^&(^&(&^*&^

	int array[10] ={1};
	x=0;
	int *pa = array;
	while(x<10)
	//printf("Array = %d\n", array[x++]);
	printf("Array [%i]= %d\n", x, pa[x++]);

	//=====================================

	int normal = 999;

	int *pn = &normal;

	printf("Adresa lui normal este %p si valoarea sa este %d", pn, *pn);
*/


	return 0;

}


char * invers(char *sentence, int nr)
{
	printf("Sentence says _%s_\n", sentence);
	int x, y;
	char *prop_inv =(char*) malloc(nr*sizeof(char));
	//char *prop_inv = calloc(nr, sizeof(char));//initializeaza blocul de memorie cu 0

	for(x=nr-1, y=0; x>= 0; x--, y++)
	/*(&%$&*(*)&*^%$^&*(&(^%%&****&&(^^*&^^*(*&^&(&*^&%*^(&)*^&%*^(*
	* am nr-1 pentru ca nr include si null terminator ('\0')
	*&%#^&*^(^%&$^%#$^%&^*&^%#^^$%&^*&%$^&%*^&^&^&%*^(*&^$&*/
	{
		prop_inv[y] = sentence[x];
	}

	printf("Prop_inv is _%s_\n", prop_inv);

	return prop_inv;
}

//! de aprodundat!
char * invers2(char *sentence, int nr)
{
	int x, y;
	char prop_inv[100]; 	//! nu functioneaza pentru ca returnezi adresa unei variabile locale
											//! care nu o sa mai existe odata ce termini functia
											//! (vezi ce facea gookin)!!!

	for(x=nr-1, y=0; x>= 0; x--, y++)
	{
		prop_inv[x] = sentence[y];
	}

	return (prop_inv);
}
