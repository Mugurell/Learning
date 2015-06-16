/* Write a function called my_strcpy that is similar to strcpy 
but will not overflow the destination array. 
The result of the copy must be a true string. 
*/


#include <stdio.h>
#include <strlcpy.h>

void my_strcpy(const char* src);

int main(void)
{
    char src[100];

    puts("\nSay something nice! (pref < 10 chars)");
    fgets(src, 100, stdin);
    my_strcpy(src);

    return 0;
}

void my_strcpy(const char* src)
{
    char dest[10];

    printf("\nDestination array previously was\n\t");
    puts(dest);

    size_t len = 0;
    len = strlcpy(dest, src, sizeof dest);
    if (len >= sizeof dest) {
        printf("Error: Too big!");
        return ;
    }

    printf("\nDestination array now is\n\t");
    puts(dest);
}