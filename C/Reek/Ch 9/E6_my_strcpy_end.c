/* 
** Write a strcpy replacement called my_strcpy_end that returns a 
** pointer to the end of the destination string (that is, a pointer 
** to the NUL byte) rather than a pointer to the beginning of the 
** destination string. 
*/

#include <stdio.h>

char *my_strcpy_end(char *dest, const char *src);

int main(void)
{
  
    char first[100] = { "" };
    char second[100] = { "" };
    char *buffer;

    puts("\n\tSay something nice:");
    fgets(first, 50, stdin);

    puts("Cool! first you had..\n");
    int x = 0;
    while (second[x] != '\0') {
        printf("%p says %c\n", &second[x], second[x]);
        x++;
    }

    puts("\nBut after copying, that exact string now's hushing..\n");
    buffer = my_strcpy_end(second, first);

    putchar('\n');
    x = 0;
    while (second[x] != '\0') {
        printf("%p says %c\n", &second[x], second[x]);
        x++;
    }
    puts("\nAnd the function that did all this returned:");
    printf("%p which says %c\n\t", buffer, *buffer);
    puts("( It's actually the nul byte ;-) )\n");

    return 0;
}

char *my_strcpy_end(char *dest, const char *src)
{
	while(*dest++ = *src++)
		;

	return dest-1;
}