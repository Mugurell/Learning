/* Write the function 
void my_strncat( char *dest, char *src, int dest_len );
which concatenates the string in src to the end of the string in dest, 
making sure not to overflow the dest array, which is dest_len bytes long.
Unlike strncat, this function takes accounts for the length of string
already in dest thereby insuring that the array bounds are not exceeded. 
*/

#include <stdio.h>
#include <string.h>

void my_strncat(char* first, char* src, int dest_len);

int main(void)
{
    int len = 20;
    char first[20] = { "" };
    char second[20] = { "" };

    puts("\n\tSay something nice:");
    fgets(first, 100, stdin);
    puts("\n\tAgain please:");
    fgets(second, 100, stdin);

    puts("Cool! So you've said..:\n\tConcatenated..\n");
    my_strncat(first, second, len);
    putchar('\n');

    return 0;
}

void my_strncat(char* first, char* src, int dest_len)
{
    char dest[dest_len];
    char* first_copy = first;
    char* second_copy = src;
    signed int first_len = 0;
    signed int second_len = 0;

    /*
	** Find out how big is the initial array.
	** To not use strlen, but my own implementation:
	*/
    while (*first) {
        first_len++; /* lenght of the first array */
        first++;
    }
    first = first_copy;
    first_len++; /* account for the nul */

    /*
	** If the dest array is allready too big, return with an error
	** Otherwise, compute the remaining space
	*/
    if (first_len - dest_len >= 0) {
        puts("Error - 1st argument is just too big!");
        return;
    }
    dest_len -= first_len; /* also accounts for the nul */

    /*
    ** Figure out how much room is needed
    */
    while (*src) {
        second_len++;
        src++;
    }
    src = second_copy;

    /*
    ** If the array to be concatenated is smaller than the available
    ** space, make sure to copy the right amount.
    ** If it is bigger, just the ramaining space will be copied.
    */
    if (dest_len > second_len)
        dest_len = second_len;

    /*
	** Copy the first array in the dest array.
	** Concatenate the second array to the dest array.
	*/
    memcpy(dest, first, first_len);
    /* both first_len and dest_len have space for the nul */
    memcpy(dest + (first_len - 1), src, dest_len);
    dest[first_len + dest_len] = '\0';

    //   for(int x = 0; x < 20; x++)
    // 	printf("%c", dest[x]);

    putchar('\n');

    puts(dest);
}
