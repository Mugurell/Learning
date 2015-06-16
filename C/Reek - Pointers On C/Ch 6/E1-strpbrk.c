/*
** Find the first occurrence in ’str’ of any of the characters in ’chars’
** and return a pointer to that location. If none are found, or if 
**’str’ or ’chars’ are NULL pointers, a NULL pointer is returned.
*/

#include <stdio.h>

char *find_char(char const *source, char const *chars);
				/*const as to show they are not to be modified*/

int main(void)
{
	char srs[100];
	char chr[10];
	
	puts("\n\tSay something nice:");
	fgets(srs, 100, stdin);
	puts("\tNow what do you want to search for in it?");
	fgets(chr, 10, stdin);

	int x = 0;
	for(; srs[x] != '\0'; ++x)
		printf("%p says %c\n", &srs[x], srs[x]);
	/*nu am mai pus ca si punct de plecare pt for "srs[x]" / "srs[0]"
	**pentru ca arrayul oricum incepe de la primul element sa "curga"*/
	/* citeste inca un caracter - defapt e linia noua citita de fgets*/

	char *temp = find_char(srs, chr);
	printf("\nThe first match is at %p - %c\n\n", temp, *temp);

	return 0;
}

char *find_char(char const *str, char const *chars)
{
	char *cp;	/*altfel - segmentation fault*/

	/*
	** Check arguments for NULL
	*/
	if(str != NULL && chars != NULL) {

		/*
		** Look at 'str' one character at a time.
		*/

		for(; *str != '\0'; str++) {

			/*
			** Look through 'chars' one at a time
			** for a match with *str.
			*/
			for(cp = chars; *cp != '\0'; cp++)
				if(*str == *cp)
					return str;
		}
	}

	return NULL;
}
