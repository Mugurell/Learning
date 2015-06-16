/* Write the function 
void my_strncat( char *dest, char *src, int dest_len );
which concatenates the string in src to the end of the string in dest, 
making sure not to overflow the dest array, which is dest_len bytes long.
Unlike strncat, this function takes accounts for the length of string
already in dest thereby insuring that the array bounds are not exceeded. 
*/

#include <stdio.h>
#include <string.h>

void my_strncat(char* dest, char* src, int dest_len);

int main(void)
{
    int len = 20;
    char first[20] = { "" };
    char second[20] = { "" };

    puts("\n\tSay something nice:");
    fgets(first, 20, stdin);
    puts("\n\tAgain please:");
    fgets(second, 20, stdin);

    puts("Cool! So you've said..:\n\tConcatenated..\n");
    my_strncat(first, second, len);
    putchar('\n');
    int x = 0;
    while (first[x] != '\0') {
        printf("%p says %c\n", &first[x], first[x]);
        x++;
    }

    return 0;
}

void my_strncat(char* dest, char* src, int dest_len)
{
    int len;
    //  char array[dest_len] = { "" };

    /*
    ** Get lenght of existing string in destination buffer; deduct this
    ** lenght from dest_len. The "+1" accounts for the terminating NUL
    ** byte that is appended.
    */
    len = strlen(dest);
    dest_len -= len + 1;

    /*
    ** If there is any room left, call memcpy to do the work.
    */
    if (dest_len > 0)
        memcpy(dest + len, src, dest_len * sizeof *src);
}
