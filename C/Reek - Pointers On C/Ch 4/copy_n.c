#include <stdio.h>

#define CHAR_NR 100
/* Declaring a function a;long with (not required) arguments*/
void copy(char dst[], char str[], int n);

int main(void)
{
	char string[CHAR_NR];
	char dest[CHAR_NR];
	int n;

	puts("Say something to be copied:");
	fgets(string, CHAR_NR, stdin);
	puts("How many of it's characters do you want to be copied?");
	scanf("%d", &n);
	puts("Okey... \n\tLet's see..\n");
	copy(dest, string, n);
	puts("So now the destination string should be..");

	/* 
	** Because strings are sent to a function by reference
	** any modification done in the funcion
	** is like being made in the send string
	** So -> we can print the dest string here
	** after it's been initialized in the below function
	*/
	puts(dest);
	puts("\n\n");

	return 0;
}

void copy(char dst[], char str[], int n)
{
	int x = 0;

	do {
		(dst[x] = str[x]);
		x++;
	} while(x < n);


	if(n < CHAR_NR)
		while(x <= CHAR_NR)
			dst[x++] = '*';
}
