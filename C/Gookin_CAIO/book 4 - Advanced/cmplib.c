#include <stdio.h>
#include "cmplib.h"
/*
int main(void)
{
	char str1[] = "Asta E o propozitie";
	char str2[] = "Asta e alta propozitie";
	char str3[] = "Asta E alta propozitie";

	 printf("str1 comparat cu str2 = %d\n\n\n", c_sensitive(str2, str3));

	 printf("str1 comparat cu str2 = %d", c_insensitive(str2, str3));


	getchar();
	return 0;
}
*/




/**********case sensitive*****************************/
int c_sensitive(char *a, char *b)
{
	int x;

	for(x=0; a[x] != '\0' && b[x] != '\0'; x++)
	{
		if(a[x] > b[x])
		return 1;
		else if(a[x] < b[x])
			return -1;
	}

	return 0;
}





int c_insensitive(char *a, char *b)
{
	int x=0;

	while(a[x] != '\0')
	{
		if(a[x] >96 && a[x] < 123)
			a[x] -= 'a' - 'A';
		x++;
	}

	x =0;
	while(b[x] != '\0')
	{
		if(b[x] >96 && b[x] < 123)
			b[x] -= 'a' - 'A';
		x++;
	}



	for(x=0; a[x] != '\0' && b[x] != '\0'; x++)
	{
		if(a[x] > b[x])
		return 1;
		else if(a[x] < b[x])
			return -1;
		else
			continue;
	}

	return 0;
}